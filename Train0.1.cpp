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

void Enquiry(string start, string target, string id, const Date &date) {
	map<string, string, string>::iterator it;
	map<string, string, string> a, b;
	
	a = quiry.lower_bound("A0000");
	b = quiry.upper_bound("Z9999") - 1;
	
	for (it = a; it != b; it++)
		it.third = 
	
}
/** wtl
  * �޸�Ʊ�������ҵ����ļ����λ�ã����복���޸ģ�������ļ�
*/
void modifyTicket(string start, string target, string id, const Date &date) {
	
}

/** wtl
  * ����
*/
void insert(const Train &nod) {
	
}

/**
  * ɾ��
*/
void erase(const Train &nod) {
	
}

/**
  * �޸�
*/
void modify() {

}

