#ifndef __TICKET__
#define __TICKET__
#include <string>
#include "toolSet.hpp"
#include "exceptions.hpp"
using std::string;

class ticket{
private:
    string start;
    string startTime;
    string dest;
    string destTime;
    int num;
    string trainid;
    string kind;
    string date;
    string price;
public:
    ticket() {}

    ticket(const string &s, const string st, const string &d, const string &dt, int n,const string &tid, const string &k,const string &da):
        start(s), startTime(st), dest(d), destTime(dt), num(n),trainid(tid),kind(k),date(da){}

    bool operator ==(const ticket &other){
        if (start != other.start) return false;
        if (dest != other.dest) return false;
        if (trainid != other.trainid) return false;
        if (kind != other.kind) return false;
        if (date != other.date) return false;
        if (startTime != other.startTime) return false;
        if (destTime != other.destTime) return false;
        return true;
    }
    void changenum(int k, double singlePrice){
        if (num + k < 0) throw notEnoughTicket{};
        num+=k;
        double tmp = littleTool::str2Dou(price) +  singlePrice * k;
        price = littleTool::dou2Str(tmp) + ' ';
    }
    int getNum() const {
    	return num;
    }
    void read(fstream &fin){
        fin >> start >> dest >> num >> trainid >> kind >> date >> price;
    }
     void write(fstream &fout) const {
        fout << start << ' '<< dest << ' ' << num << ' ' << trainid << ' ' << kind << ' ' << date << ' ' << price << ' ';
    }

     string query() {
         string res = trainid + ' ';
         res += start + ' ' + startTime + ' ';
         res += dest + ' ' + destTime;
         res += date + ' ' + kind + ' ' + price + ' ' + littleTool::int2String(num) + ' ';
         return res;
     }
};
#endif
