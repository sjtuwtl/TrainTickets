#ifndef LOGCLASS_H
#define LOGCLASS_H

#include <string>
#include <fstream>
#include "TrainClass.hpp"
#include "UserClass.hpp"

using std::ios;

using std::string;
using std::ofstream;
using std::ifstream;
using std::fstream;

class logClass {
    ofstream fo;
    string file;
    int size;
public:
    logClass(){}
    logClass(const string &t):file(t), fo(t, ios::app),size(0){}
    logClass(char *t):file(t), fo(t),size(0){}

    string getFile() { return file; }

    void user_registerLog(const User &x) {
        ++size;
        if (x.isAdmin()) fo << "Administritor Register ID: " <<x.getID()<<" Name: "<<x.getname()<< '\n';
        else fo << "User Register ID: " << x.getID() << "Name: " << x.getname() << '\n';
        fo.close();
    }
    void user_modifyLog(const User &x) {
        ++size;
        fo << "User Modify ID: " <<x.getID()<<" Name: "<<x.getname()<< '\n';
        fo.close();
    }
    void admin_insertLog(const Train &x) {
        ++size;
        fo << "Train Insert Name: "<<x.Name<< '\n';
        fo.close();
    }
    void admin_deleteLog(const Train &x) {
        ++size;
        fo << "Train Delete Name: "<<x.Name<< '\n';
        fo.close();
    }
    void admin_modifyLog(const Train &x,const Train y) {
        ++size;
        fo << "Train Modify Name: "<<x.Name<< '\n';
        fo << "To: "<<y.Name<< '\n';
        fo.close();
    }
    int getSize(){return size;}

    void userTicket(const User &usr, const string &opt, const string &start, const string &dest, const string &trainid, const string &kind, const string &num) {
        ++size;
        fo << "Ticket Operation: " << usr.getname() << ' ' << usr.getID() << ' ' << opt << ' ' << num << ' ' << kind << " tickets of " << trainid << " from" << start << " to " << dest << ".\n";
    }

    void userLogin(const User &usr) {
        ++size;
        if (!usr.isAdmin())
            fo << "User Login: " << usr.getname() << ' ' << usr.getID() << '\n';
        else
            fo << "Administritor Login: " << usr.getname() << ' ' << usr.getID() << '\n';
    }
};



void insertTrain(const Train &train, logClass &log);

void delTrain(const Train &train, logClass &log);

void insertTrain(const Train &train, logClass &log);

void delTrain(const Train &train, logClass &log);

#endif // LOGCLASS_H
