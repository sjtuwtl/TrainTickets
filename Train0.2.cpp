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
void addTrain(string *title, int titleLen, string *list, int listLen) {
	
}

/** 
  * 本函数已完成
  * 把车次添加到mp里面 
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
  * 修改票数，先找到在文件里的位置，读入车，修改，输出到文件
*/
void modifyTicket(const string &start, const string &target, const string &trainNum, const Date &date, const string DangWei, const int numb, TMAP &TrainMap) {
	map<Key, int>::iterator it, a, b;
	Train t;
	
	//这里需要把档位转化为数字
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
  * 插入
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
  * 删除
*/ 
void erase(const Train &nod, TMAP &TrainMap, int &total) {
	int i = 1;
	Train t;
	while (1) {
		inf.seekg((i - 1) * sizeof(Train) + sizeof(int));
		inf.read( reinterpret_cast<char *> (&t), sizeof(Train) );
		if (t == nod) break;//这里需要在train类里写一个==的重载 
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
	//清空最后一个 
}

/**
  * 修改
*/
void modify() {

}
