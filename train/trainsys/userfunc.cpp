#include <string>
#include "UserClass.hpp"
#include "varset.h"
#include "logclass.h"
using std::string;

int login(const string &userid, const string &password, bool flag){
    int id=littleTool::string2Int(userid);
    if (userMap.count(UserInformation(id)) == 0) return 0;
    int pos = userMap[UserInformation(id)];
    User &a=userList[pos];
    if (a.isAdmin() != flag) return 0;
    if (a.getpass()==password) {
        curUser = &userList[pos]; //全局变量
        curLog = &userLog[pos];
        curLog->userLogin(*curUser);
        sysLog.userLogin(*curUser);
        return 1;
    }
    return 2;
}

string trueRegister(const string &s1, const string &s2, bool is_admin){
    int res;
    if (userMap.empty()) {
        res = 0;
    }
    else {
        UMAP::iterator it = userMap.end(); it--;
        res = (int)it -> first + 1;
    }
    User x(res , s1, s2, is_admin);
    UserInformation j = UserInformation(x.getID());
    pair<UserInformation, int> userp(j, userList.size());
    userMap.insert(userp);
    userList.push_back(x);

    string userID = littleTool::id2String(res, 9);
    userLog.push_back(userID + ".log");
    userLog[userLog.size() - 1].user_registerLog(x);
    sysLog.user_registerLog(x);

    return userID;
}

void changeInfo(string userName, string userPass) {
    if (userName != "") curUser->modifyName(userName);
    if (userPass != "") curUser->modifyPswd(userPass);

    curLog->user_modifyLog(*curUser);
    sysLog.user_modifyLog(*curUser);
}

string User::queryTicket() {
    string res = "";
    for (vector<ticket>::iterator it = Tic.begin(); it != Tic.end(); ++it) {
        res = res + (it -> query());
    }
    return res;
}


void ticketUsrOpt(const  string &UsrOpt, const  string &TicketNum, const  string &TicketClass, const  string &TrainId, const  string &Start, const  string &Target, const  string &Date) {
    User &tmp = *curUser;
    Train train = modifyTicket(Start, Target, TrainId, Date, TicketClass, littleTool::string2Int(TicketNum), trainMap);
    if (UsrOpt == "bought") {
        tmp.editticket(Start, Target, littleTool::string2Int(TicketNum), train, TicketClass, Date);
        curLog->userTicket(*curUser, "bought", Start, Target, TrainId, TicketClass, TicketNum);
        sysLog.userTicket(*curUser, "bought", Start, Target, TrainId, TicketClass, TicketNum);
    }
    else {
        tmp.editticket(Start, Target, -littleTool::string2Int(TicketNum), train, TicketClass, Date);
        curLog->userTicket(*curUser, "refunded", Start, Target, TrainId, TicketClass, TicketNum);
        sysLog.userTicket(*curUser, "refunded", Start, Target, TrainId, TicketClass, TicketNum);
    }
}
