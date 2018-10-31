#include <fstream>
#include "UserClass.hpp"
#include "logclass.h"
#include "varset.h"
#include "exceptions.hpp"
#include "TrainClass.hpp"

using std::string;
using std::fstream;

bool insertTrain(const string &name, string *title, int titleLen, string list[][15], int listLen){
    Train train(name, title, titleLen, list, listLen, (int)trainList.size());
    for (int i = 0; i < trainList.size(); ++i) {
        if (trainList[i] == train) return false;
    }
    trainList.push_back(train);
    train.inTree(trainMap);
    sysLog.admin_insertLog(train);
    curLog->admin_insertLog(train);
    return true;
}

int delTrain(const string &trainId){
    for (int i = 0; i < trainList.size(); ++i) {
        if (trainList[i].getName() == trainId) {
            if (trainList[i].beSold(string("2017-03-28")))
                       return -1;
            trainList[i].outTree(trainMap);
            sysLog.admin_deleteLog(trainList[i]);
            curLog->admin_deleteLog(trainList[i]);
            std::swap(trainList[i], *(trainList.end() - 1));
            trainList.pop_back();
            return 1;
        }
    }
    return 0;
}

int changeTrain(const string &name, string *title, int titleLen, string list[][15], int listLen) {
    for (int i = 0; i < trainList.size(); ++i) {
        if (trainList[i].getName() == name) {
            Train t1 = trainList[i];
            if (trainList[i].beSold("2017-03-28")) return -1;
            delTrain(name);
            insertTrain(name, title, titleLen, list, listLen);
            sysLog.admin_modifyLog(t1, trainList.back());
            curLog->admin_modifyLog(t1, trainList.back());
            return 1;
        }
    }
    return 0;

}

bool updateSell(const string &trainId, const string &date, bool flag) {
    for (int i = 0; i < trainList.size(); ++i) {
        if (trainId == trainList[i].getName()) {
            trainList[i].setSold(date, flag);
            return 1;
        }
    }
    return 0;
}

bool seeUser(int userid, string &text1, string &text2, string &text4){
    if (userMap.count(userid) == 0) return 0;
    int k = userMap[userid];
    User usr = userList[k];
    text1 = usr.getname();
    text2 = usr.getpass();

    ifstream fin(userLog[k].getFile());
    text4 = "";
    string tmp;
    while (getline(fin, tmp)) {
        text4 += tmp + '\n';
    }
    return 1;
}

string checkLog() {
    string res = "", tmp;
    ifstream fin(sysLog.getFile());
    while (getline(fin, tmp)) {
        res += tmp + '\n';
    }
    return res;
}
