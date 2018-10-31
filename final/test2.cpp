#include <cstdio>
#include <iostream>
#include <fstream>
#include <sstream>
#include <cstring>
#include <vector>
#include "utility.hpp"
using namespace std;

#include "linkList.hpp"
#include "map.hpp"

#include "toolSet.hpp"		
#include "classSet2.hpp"

const char TrainFile[] = "Train.inf";
const char UserFile[] = "User.inf";
const char TrainTree[] = "TrainTree.config";
const char UserTree[] = "UserTree.config";
const char TrainLog[] = "TrainOpt.log"; 


typedef MyMap<QueryInformation> TMAP;
typedef MyMap<UserInformation> UMAP;

#include "UserClass.hpp"
#include "TrainClass.hpp"

vector<Train> trainList;
vector<User> userList;

void outTrainList() {
	fstream file(TrainFile, fstream::out | ios::binary | ios::trunc);
	size_t sz = trainList.size();
	file.write(reinterpret_cast<const char *> (&sz), sizeof sz);
	for (int i = 0; i < trainList.size(); ++i) {
		trainList[i].write(file);
	}
	file.close();
}

void outUserList() {
	fstream file(UserFile, fstream::out | ios::binary | ios::trunc);
	size_t sz = userList.size();
	file.write(reinterpret_cast<const char *> (&sz), sizeof sz);
	for (int i = 0; i < sz; ++i) {
		userList[i].write(file);
	}
	file.close();
}

void modifyTicket(const string &start, const string &target, const string &trainNum, const string &dateString, const string &DangWei, int ticketNum, const TMAP &TrainMap) {	
	TMAP::const_iterator it, a, b;
	
	int k;
	Time date(dateString);
	k = littleTool::matchSeat(DangWei);
	it = TrainMap.find(QueryInformation(start, target, trainNum));
	if (it == TrainMap.end()) throw noSuchTrain{};
	Train &t = trainList[it -> second];
	
	
	if (!t.checkRemain(start, target, ticketNum, date, k)) throw notEnoughTicket{};
	t.modifyRemain(start, target, ticketNum, date, k);	
}

void inTrainTree(const char *inFile, TMAP &mp) {
	fstream fin(inFile, fstream::in|ios::binary);
	mp.read(fin);
	fin.close();
}

void inUserTree(const char *inFile, UMAP &mp) {
	fstream fin(inFile, fstream::in|ios::binary);
	mp.read(fin);
	fin.close();
}

void outUserTree(const char *outFile, const UMAP &mp) {
	fstream fout(outFile, fstream::out | ios_base::trunc);
	mp.write(fout);
	fout.close();
}

void ticketOpt(string *list, const TMAP &trainMap, UMAP &userMap, const char *userFile) {
	enum userInf{UsrName, UsrId, UsrOpt, TicketNum, TicketClass, TrainId = 7, Start = 9, Target = 11, Date = 13};
	int Id = 0, len = list[UsrId].length(),  pos;
	size_t size;
	for(int i = 0; i < len; ++ i){
		Id *= 10;
		Id += list[UsrId][i] - '0';
	}
	if(userMap.find(Id) == userMap.end()){
		User tmp(Id, list[UsrName]);
		userMap[Id] = (int)userList.size();
		userList.push_back(tmp);
	}
	pos = userMap[UserInformation(Id)];
	User &tmp = userList[pos];
	if (list[UsrOpt] == "bought")
		tmp.editticket(list[Start], list[Target], littleTool::string2Int(list[TicketNum]), list[TrainId], list[TicketClass], list[Date]);
	else {
		tmp.editticket(list[Start], list[Target], -littleTool::string2Int(list[TicketNum]), list[TrainId], list[TicketClass], list[Date]);
	}
	modifyTicket(list[Start], list[Target], list[TrainId], list[Date], list[TicketClass], littleTool::string2Int(list[TicketNum]), trainMap);
}

int divideString(string inString, string *res, char divSymbol) {
	istringstream sin(inString);
	int len = 0;
	for (len = 0; getline(sin, res[len], divSymbol); ++len);
	return len;
}

TMAP trainMap;
UMAP userMap;

void readOptFile(const char *inFile) {
	ifstream Oin(inFile);
	Oin.seekg(0);
	
	string tmp = "", list[14];
	int _index = 0;
	while (getline(Oin, tmp)) {
cout << ++_index << endl;
		int len = divideString(tmp, list, ' ');
		ticketOpt(list, trainMap, userMap, UserFile);
	}
	Oin.close();
	
}

void inUserList() {
	fstream file(UserFile, fstream::in | ios::binary);
	size_t sz;
	userList.clear();
	file.read(reinterpret_cast<char *>(&sz), sizeof sz);
	for (int i = 0; i < sz; ++i) {
		User tmp;
		tmp.read(file);
		userList.push_back(tmp);
	}
	file.close();
}

void inTrainList() {
	fstream file(TrainFile, fstream::in | ios::binary);
	size_t sz;
	file.read(reinterpret_cast<char *>(&sz), sizeof sz);
	trainList.clear();
	for (int i = 0; i < sz; ++i) {	
		Train tmp;
		tmp.read(file);
		trainList.push_back(tmp);
	}
	file.close();
}

int main() {

	inTrainTree(TrainTree, trainMap);		//read the trainMap
	inUserTree(UserTree, userMap);			//read the userMap 
	inTrainList();
	inUserList();
	readOptFile("operations.out");//split the information in the data and call the ticket operation.
	outUserTree(UserTree, userMap);	
	outUserList();
	outTrainList();
/*
	inUserList();
	cout << userList.size() << endl;
	for (int i = 0; i < 20; ++i) userList[i].testPrint();
	cout << endl;
	*/
}
