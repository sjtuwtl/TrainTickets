#include <cstdio>
#include <iostream>
#include <fstream>
#include <sstream>
#include <cstring>
#include <map>
using namespace std;

#include "classSet.hpp"
#include "trainClass.hpp"
#include "userClass.hpp"

typedef MyMap<QueryInformation> TMAP;
typedef MyMap<int> UMAP;


/** nh
  * construct a train class and add the train in the file
*/
void addTrain(string *title, int titleLen, string **list, int listLen) {	
	Train tmp;
	for(int i = 0; i < listLen; ++ i){
		tmp.ZhanTai.insert(list[i][0]);
		Time tmp1(list[i][1]), tmp2(list[i][1]);
		if(list[i][2] != "起点站") tmp1.Add(list[i][2]);
		if(list[i][3] != "终到站") tmp2.Add(list[i][3]);
		tmp.Arrival.preInsert(tmp.Arrival.end(), tmp1);
		tmp.Dapart.preInsert(tmp.Dapart.end(), tmp2);
		int num = 0, pos = 0;
		while(list[i][4][pos] >= '0' && list[i][4][pos] <= '9'){
			num *= 10; num += list[i][4][pos] - '0';
		}
		tmp.Kilometer.preInsert(tmp.Kilometer.end(), num);
		for(int j = 5; j <= titleLen; ++ j){
			double tot;
			tot = littleTool::str2Dou(list[i][j]);
			tmp.Price[i].preInsert(tmp.Price[i].end(), tot);
		}
	}
	tmp.write();
}

/** 
  * construct the trainMap
*/
void buildTrain(char *inFile, map<QueryInformation, int> &mp) {
	fstream inTree(inFile);
	size_t size;
	inTree.read(reinterpret_cast<char *> (&size), sizeof size); //the number of trains.
	
	Train nod;
	for (int i = 0; i < size; ++i) {
		nod.seekg(Train::SIZE * i + sizeof(size_t));
		nod.read(inTree);
		insert(nod);
	}
}

/**
  * do the searching work
*/
void Enquiry(const string &start, const string &target, const string &trainNum, const Time &date, TMAP &TrainMap) {
	fstream inf(TrainFile);
	map<Key, int>::iterator it, a, b;
	Train t;
	a = TrainMap.lower_bound(QueryInformation(start, target, "A0000"));
	b = TrainMap.upper_bound(QueryInformation(start, target, "Z9999")) - 1;
	
	for (it = a; it != b; it++) {
		inf.seekg((it->second - 1) * Train::SIZE + sizeof(size_t));
		t.read(inf);
		list<string>::iterator i;
		list<int>::iterator j;
		int mmin[11];
		for (int h = 0; h <= 9; h++) mmin[h] = 10000;
		for (int k = 0; k <= 9; k++) {
			j = t.Remain[date - date0][k].begin();
			for (i = t.ZhanTai.begin(); i != t.ZhanTai.end(); ++i) {
				j++;
				bool f = false;
				if (*i == start) f = true;
				if (f) {
					if (mmin[k] > *j) mmin[k] = *j;
				}
				if (*i == target) f = false;
		    }
	    }
		for (int h = 0; h <= 9; h++) if (mmin[h] != 10000 && minn[h] > 0) PrintTrain(it, h);
	}
	
}

/** wtl
  * change the train in the Train.inf
*/
void modifyTicket(const string &start, const string &target, const string &trainNum, const Time &date, const string &DangWei, int ticketNum, TMAP &TrainMap) {	
	fstream inf(TrainFile);
	TMAP::iterator it, a, b;
	Train t;
	int k;
	it = TrainMap.find(QueryInformation(start, target, trainNum));
	if (it == TrainMap.end()) throw noSuchTrain{};
	inf.seekg((it->second - 1) * Train::SIZE + sizeof(size_t));
	t.read(inf);
	list<string>::iterator i;
	list<int>::iterator j;
	 
	j = t.Remain[date - date0][k].begin();
	bool t = true;
	for (i = t.ZhanTai.begin(); i != t.ZhanTai.end(); ++i) {
		bool f = false;
		if (*i == start) f = true;
		if (f) {
			if (*j < ticketNum) t = false; 
		}
		if (*i == target) f = false;
		j++;
	}
	if (t) {
		for (i = t.ZhanTai.begin(); i != t.ZhanTai.end(); ++i) {
			j++;
			bool f = false;
			if (*i == start) f = true;
			if (f) {
				(*j) -= ticketNum; 
			}
			if (*i == target) f = false;
		}
		inf.seekp((a->second - 1) * Train::SIZE + sizeof(size_t));
		t.write(inf);
		inf.close();
	}
	
}

/** wtl
  * add the train class in the tree
*/
void insertTrain(const Train &nod, TMAP &TrainMap) {
	fstream inf(TrainFile);
	size_t tmp;
	inf.seekg(0);
	inf.read(reinterpret_cast<char *> (&tmp), sizeof tmp);
	tmp++;
	inf.seekp(0);
	inf.write(reinterpret_cast<const char *> (&tmp), sizeof tmp);
	inf.seekp((tmp - 1) * Train::SIZE + sizeof(size_t));
	nod.write(inf);
	list<string>::iterator i, j;
	for (i = nod.ZhanTai.begin(); i != nod.ZhanTai.end(); i++)
		for (j = i, j++; j != nod.ZhanTai.end(); j++)
			TrainMap.insert(QueryInformation(*i, *j, nod.Name));
}

void insert(const Train &nod, TMAP &TrainMap){
	list<string>::iterator i, j;
	for (i = nod.ZhanTai.begin(); i != nod.ZhanTai.end(); i++)
		for (j = i, j++; j != nod.ZhanTai.end(); j++)
			TrainMap.insert(QueryInformation(*i, *j, nod.Name));
}


/**
  * erase the train class in the tree
*/
void eraseTrain(const Train &nod, TMAP &TrainMap) {
	int i = 1;
	Train t;
	size_t tmp;
	inf.seekg(0);
	inf.read(reinterpret_cast<char *> (&tmp), sizeof tmp);
	while (1) {
		inf.seekg((i - 1) * Train::SIZE + sizeof(size_t));
		t.read(inf);
		if (t == nod) break;
		i++;
	}
	inf.seekg((tmp - 1) * Train::SIZE + sizeof(size_t));
	t.read(inf);
	inf.seekp((i - 1) * Train::SIZE + sizeof(size_t));
	t.write(inf);
	tmp--;
	inf.seekp(0);
	inf.write(reinterpret_cast<const char *> (&tmp), sizeof tmp);
	list<string>::iterator i, j;
	for (i = nod.ZhanTai.begin(); i != nod.ZhanTai.end(); i++)
		for (j = i, j++; j != nod.ZhanTai.end(); j++)
			TrainMap.erase(QueryInformation(*i, *j, nod.Name));
}
void erase(const Train &nod, TMAP &TrainMap) {
	list<string>::iterator i, j;
	for (i = nod.ZhanTai.begin(); i != nod.ZhanTai.end(); i++)
		for (j = i, j++; j != nod.ZhanTai.end(); j++)
			TrainMap.erase(QueryInformation(*i, *j, nod.Name));
}

