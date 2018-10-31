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
  * title��һ���ַ������飬��ʾ����ı�ͷ��list��ʾ����ÿ����ͷ��Ӧ����Ϣ
  * Ҫ�����°ѻ𳵼ӵ��������ļ�����
*/
void addTrain(string *title, int titleLen, string *list, int listLen) {
	
}

/** 
  * �����������
  * �ѳ�����ӵ�mp���� 
*/
void buildTrain(char *inFile, map<QueryInformation, int> &mp) {
	ifstream inTree(inFile);
	int size;
	inTree.read(reinterpret_cast<char *> (&size), sizeof(int)); //the number of trains.
	
	Train nod;
	for (int i = 0; i < size; ++i) {
		inTree.read(reinterpret_cast<char *> (&nod), sizeof(nod));
		insert(nod);
	}
}

void Enquiry((const string &start, const string &target, const string &trainNum, const Date &date, TMAP &TrainMap) {
	map<Key, int>::iterator it, a, b;
	Train t;
	a = TrainMap.lower_bound(QueryInformation(start, target, "A0000"));
	b = TrainMap.upper_bound(QueryInformation(start, target, "Z9999")) - 1;
	
	for (it = a; it != b; it++) {
		inf.seekg((it->second - 1) * sizeof(Train) + sizeof(int));
		inf.read( reinterpret_cast<char *> (&t), sizeof(Train) );
		list<string>::iterator i;
		list<int>::iterator j;
		int mmin[11];
		for (int h = 0; h <= 9; h++) mmin[h] = 10000;
		for (int k = 0; k <= 9; k++) {
			j = t.Remain[date][k].begin();
			if (*j == 0)
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
  * �޸�Ʊ�������ҵ����ļ����λ�ã����복���޸ģ�������ļ�
*/
void modifyTicket(const string &start, const string &target, const string &trainNum, const Date &date, const string DangWei, const int numb, TMAP &TrainMap) {
	map<Key, int>::iterator it, a, b;
	Train t;
	
	//������Ҫ�ѵ�λת��Ϊ����
	int k = ...;
		inf.seekg((it->second - 1) * sizeof(Train) + sizeof(int));
		inf.read( reinterpret_cast<char *> (&t), sizeof(Train) );
		list<string>::iterator i;
		list<int>::iterator j;
		 
			j = t.Remain[date - date0][k].begin();
			for (i = t.ZhanTai.begin(); i != t.ZhanTai.end(); ++i) {
				j++;
				bool f = false;
				if (*i == start) f = true;
				if (f) {
					for (int h = 1; h <= numb; h++) (*j)--; 
				}
				if (*i == target) f = false;
		    }
	inf.seekp((a->second - 1) * sizeof(Train) + sizeof(int));
	inf.write( reinterpret_cast<char *> (&t), sizeof(Train) );
	inf.close();
}

/** wtl
  * ����
*/
void insert(const Train &nod, TMAP &TrainMap, int &total) {
	inf.seekp((total) * sizeof(Train) + sizeof(int));
	inf.write( reinterpret_cast<char *> (&nod), sizeof(Train) );
	++total;
	list<string>::iterator i, j;
	for (i = nod.ZhanTai.begin(); i != nod.ZhanTai.end(); i++)
		for (j = i, j++; j != nod.ZhanTai.end(); j++)
			TrainMap.insert(QueryInformation(*i, *j, nod.Name));
}

/**
  * ɾ��
*/ 
void erase(const Train &nod, TMAP &TrainMap, int &total) {
	int i = 1;
	Train t;
	while (1) {
		inf.seekg((i - 1) * sizeof(Train) + sizeof(int));
		inf.read( reinterpret_cast<char *> (&t), sizeof(Train) );
		if (t == nod) break;//������Ҫ��train����дһ��==������ 
		i++;
	}
	i++;
	while (i <= n) {
		inf.seekg((i - 1) * sizeof(Train) + sizeof(int));
		inf.read( reinterpret_cast<char *> (&t), sizeof(Train) );
		inf.seekg((i - 2) * sizeof(Train) + sizeof(int));
		inf.read( reinterpret_cast<char *> (&t), sizeof(Train) );
	}
	--total;
	//������һ�� 
}

/**
  * �޸�
*/
void modify() {

}
