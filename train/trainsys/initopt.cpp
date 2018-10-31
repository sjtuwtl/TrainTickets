#include <sstream>
#include "varset.h"
#include "toolSet.hpp"
#include "exceptions.hpp"
#include "classSet2.hpp"
#include "UserClass.hpp"
#include "TrainClass.hpp"

using std::fstream;
using std::ios;
using std::istringstream;
using std::string;
using std::ifstream;
#include <cstdio>
void inTrainTree(const char *inFile, TMAP &mp) {
    fstream fin(inFile, fstream::in);

    bool flag = fin.is_open();

    mp.read(fin);
    fin.close();
}

void outTrainTree(const char *outFile) {
    fstream fout(outFile, fstream::out | ios::trunc);
    trainMap.write(fout);
    fout.close();
}

void inUserTree(const char *inFile, UMAP &mp) {
    fstream fin(inFile, fstream::in);
    mp.read(fin);
    fin.close();
}


void outUserTree(const char *outFile, const UMAP &mp) {
    fstream fout(outFile, fstream::out | ios::trunc);
    mp.write(fout);
    fout.close();
}

void inUserList() {
    fstream file(UserFile, fstream::in);
    int sz;
    userList.clear();
    file >> sz;
    for (int i = 0; i < sz; ++i) {
        User tmp;
        tmp.read(file);
        userList.push_back(tmp);
        userLog.push_back(logClass(tmp.getID() + ".log"));
    }
    file.close();
}


void outUserList() {
    fstream file(UserFile, fstream::out | ios::trunc);
    int sz = userList.size();
printf("%d\n", sz);
    file << sz << ' ';
    for (int i = 0; i < sz; ++i) {
printf("%s", userList[i].getname().c_str());
        userList[i].write(file);
    }
    file.close();
}

void inTrainList() {
    fstream file(TrainFile, fstream::in);
    int sz;
    int t = file.is_open();
    file >> sz;
    trainList.clear();
    for (int i = 0; i < sz; ++i) {
printf("%d\n", i);
        Train tmp;
        tmp.read(file);
printf("%s\n", tmp.getName().c_str());
tmp.testPrint();
        trainList.push_back(tmp);
    }
    file.close();
}


void outTrainList() {
    fstream file(TrainFile, fstream::out | ios::trunc);
    int sz = trainList.size();
printf("%d\n", sz);
    file << sz << ' ';
    for (int i = 0; i < trainList.size(); ++i) {
        trainList[i].write(file);
    }
    file.close();
}


int divideString(string inString,  string *res, char divSymbol) {
    istringstream sin(inString);
    int len = 0;
    string tmp;
    for (len = 0; getline(sin, tmp, divSymbol); ++len) {
        if (tmp.back() == '\r' || tmp.back() == '\n' || tmp.back() == '\t') tmp.erase(tmp.end() - 1);
        res[len] = tmp;
    }
    return len;
}


void readUpdFile(const char inFile[]) {
    trainList.clear();
    ifstream Uin(inFile);
    string tr, tmp, title[15], list[110][15];
    int _index = 0;
    do {
        if (!getline(Uin, tr)) {
            break;
        }
printf("%s\n", tr.c_str());
        if (tr.back() == '\r' || tr.back() == '\n' || tr.back() == '\t') tr.erase(tr.end() - 1);
        getline(Uin, tmp);
        int n = divideString(tmp, title, ','), len = 0;
        while (true) {
            getline(Uin, tmp);
            int m = divideString(tmp, list[len], ',');
            if (list[len++][3] == "终到站") break;
        }

        Train tmp(tr, title, n, list, len, (int)trainList.size());
        trainList.push_back(tmp);
    }while (true);
    Uin.close();
}

void buildTrain(const char *inFile) {
    fstream inTree(inFile, fstream::in);

    Train nod;
    for (int i = 0; i < trainList.size(); ++i) {
        trainList[i].inTree(trainMap);
    }
    inTree.close();
}


void initUserFile(const char *userFile, const char *userTree) {
    int x = 0, y = -1;
    int size = 0;
    fstream outFile(userFile, fstream::out | ios::trunc);
    outFile << size << ' ';
    outFile.close();
    fstream outTree(userTree, fstream::out| ios::trunc);
    outTree << x << ' ' << x << ' ' << y << ' ' << x << ' ';
    outTree.close();
}

const Train &modifyTicket(const string &start, const string &target, const string &trainNum, const string &dateString, const string &DangWei, int ticketNum, const TMAP &TrainMap) {
    TMAP::const_iterator it, a, b;

    int k;
    Time date(dateString);
    k = littleTool::matchSeat(DangWei);
    it = TrainMap.find(QueryInformation(start, target, trainNum));
    if (it == TrainMap.end()) throw noSuchTrain{};
    Train &t = trainList[it -> second];


    if (!t.checkRemain(start, target, ticketNum, date, k)) throw notEnoughTicket{};
    t.modifyRemain(start, target, ticketNum, date, k);
    return t;
}


void ticketOpt(string *list, const TMAP &trainMap, UMAP &userMap, const char *userFile) {
    enum userInf{UsrName, UsrId, UsrOpt, TicketNum, TicketClass, TrainId = 7, Start = 9, Target = 11, Date = 13};
    int len = list[UsrId].length();
    int Id = 0;
    for(int i = 0; i < len; ++ i){
        Id *= 10;
        Id += list[UsrId][i] - '0';
    }
    if(userMap.find(Id) == userMap.end()){
        User tmp(Id, list[UsrName]);
        userMap[Id] = (int)userList.size();
        userList.push_back(tmp);
    }
    int pos = userMap[UserInformation(Id)];
    User &tmp = userList[pos];

    Train train = modifyTicket(list[Start], list[Target], list[TrainId], list[Date], list[TicketClass], littleTool::string2Int(list[TicketNum]), trainMap);
    if (list[UsrOpt] == "bought")
        tmp.editticket(list[Start], list[Target], littleTool::string2Int(list[TicketNum]), train, list[TicketClass], list[Date]);
    else {
        tmp.editticket(list[Start], list[Target], -littleTool::string2Int(list[TicketNum]), train, list[TicketClass], list[Date]);
    }

}

void readOptFile(const char *inFile) {
    ifstream Oin(inFile);
    Oin.seekg(0);

    string tmp = "";
     string list[14];
    while (getline(Oin, tmp)) {
        int len = divideString(tmp, list, ' ');
        ticketOpt(list, trainMap, userMap, UserFile);
    }
    Oin.close();

}
