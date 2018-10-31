
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
  * title是一个字符串数组，表示输入的表头，list表示的是每个表头对应的信息
  * 要做的事把火车加到二进制文件里面
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
  * 本函数已完成
  * 把车次添加到mp里面 
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

void Enquiry((const string &start, const string &target, const string &trainNum, const Date &date, TMAP &TrainMap) {
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
			j = t.Remain[date - data0][k].begin();
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
  * 修改票数，先找到在文件里的位置，读入车，修改，输出到文件
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
	 
	j = t.Remain[date][k].begin();
	for (i = t.ZhanTai.begin(); i != t.ZhanTai.end(); ++i) {
		j++;
		bool f = false;
		if (*i == start) f = true;
		if (f) {
			(*j) -= num; // 此处要修改
		}
		if (*i == target) f = false;
	}
	inf.seekp((a->second - 1) * Train::SIZE + sizeof(size_t));
	t.write(inf);
	inf.close();
}

/** wtl
  * 插入，要把火车从每一个站点加入
  * 维护插入日志
*/
void insert(const Train &nod, TMAP &TrainMap) {
	fstream inf(TrainFile);
	inf.seekp((total) * Train::SIZE + sizeof(size_t));
	nod.write(inf);
	++total;
}

/**
  * 删除
  * 要把火车从每一个站点删除,
  * 维护删除日志
*/
void erase(const Train &nod, TMAP &TrainMap) {
	int i = 1;
	Train t;
	while (1) {
		inf.seekg((i - 1) * Train::SIZE + sizeof(size_t));
		t.read(inf);
		if (t == nod) break;
		i++;
	}
	i++;
	while (i <= n) {
		inf.seekg((i - 1) * Train::SIZE + sizeof(size_t));
		t.read(inf);
		inf.seekg((i - 2) * Train::SIZE + sizeof(size_t));
		t.read(inf);
	}
}
/** 
  * 修改
  * 维护修改日志
*/
void modify() {
	
}
