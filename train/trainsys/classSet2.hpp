#ifndef __CLASS__
#define __CLASS__

#include <string>
#include <fstream>
#include "toolSet.hpp"

using std::string;
using std::fstream;
using std::ostream;
	
class Time {
public:
    int year, month, day;

    Time(int _year = 2017, int _month = 0, int _day = 0): year(_year), month(_month), day(_day) {}

    const static size_t SIZE = 3 * sizeof(int);
    Time(const string &Date){
        int tmp = 0, pos = 0, len = Date.length();
        while(pos < len && Date[pos] >= '0' && Date[pos] <= '9'){
            tmp *= 10; tmp += Date[pos] - '0';
            pos++;
        }
        year = tmp; tmp = 0;
        pos ++;
        while(pos < len && Date[pos] >= '0' && Date[pos] <= '9'){
            tmp *= 10; tmp += Date[pos] - '0';
            pos++;
        }
        month = tmp; tmp = 0;
        ++pos;
        while(pos < len && Date[pos] >= '0' && Date[pos] <= '9'){
            tmp *= 10; tmp += Date[pos] - '0';
            pos++;
        }
        day = tmp;
    }
    friend bool operator < (const Time &a, const Time &b) {
        return (a.year == b.year ?
                a.month == b.month?
                a.day < b.day :
                a.month < b.month :
                a.year < b.year);
    }

    friend bool operator == (const Time &a, const Time &b) {
        return (a.year == b.year && a.month == b.month && a.day == b.day);
    }

    friend bool operator != (const Time &a, const Time &b) {
        return !(a == b);
    }

    friend int operator - (const Time &a, const Time &b) {
        if (a.month == b.month) return (a.day - b.day);
        return (a.day + 31 - b.day);
    }

    void read(fstream &fin) {
        fin.read(reinterpret_cast<char *>(this), sizeof(*this));
    }

    void write(fstream &fout) const {
        fout.write(reinterpret_cast<const char *>(this), sizeof(*this));
    }
    friend ostream &operator << (ostream &fout, const Time &a) {
        fout << a.year << '_' << a.month << '_' << a.day;
        return fout;
    }
};

const Time date0(2017, 3, 28);

class QueryInformation {
public:
    string st, ed, tr;
    QueryInformation() {st = ed = tr = "0";}
    QueryInformation(char *a, char *b, char *c) {
        st = a; ed = b; tr = c;
    }
    QueryInformation(string _st, string _ed, string _tr):
        st(_st), ed(_ed), tr(_tr) {}
    friend bool operator < (const QueryInformation &a, const QueryInformation &b) {
        return a.st == b.st ? a.ed == b.ed ? a.tr < b.tr : a.ed < b.ed : a.st < b.st;
    }

    friend ostream& operator << (ostream &fout, const QueryInformation &a) {
        fout << '(' << a.st << ' ' << a.ed << ' ' << a.tr << ')';
        return fout;
    }

    friend bool operator == (const QueryInformation &a, const QueryInformation &b) {
        return a.st == b.st && a.ed == b.ed && a.tr == b.tr;
    }

    friend bool operator != (const QueryInformation &a, const QueryInformation &b) {
        return !(a == b);
    }

    void read(fstream &fin) {
        fin >> st >> ed >> tr;
    }

    void write(fstream &fout) {
        fout << st << ' ' << ed << ' ' << tr << ' ';
    }
};

class UserInformation {
public:
    int t;
    UserInformation(int _t = 0): t(_t) {}
    friend bool operator < (const UserInformation &a, const UserInformation &b) {
        return a.t < b.t;
    }

    void read(fstream &fin) {
        fin >> t;
    }

    void write(fstream &fout) {
        fout << t << ' ';
    }

    friend ostream& operator << (ostream &fout, const UserInformation &a) {
        fout << a.t;
        return fout;
    }
    operator int() const{
        return t;
    }
};
#endif
