#ifndef __classSet__
#define __classSet__

#include "linkList.hpp"
#include "toolSet.hpp"

class MyString {
public:
	string s;
	MyString() {s = "";}
	MyString(const string &_s): s(_s) {}
	void read(fstream &fin) {
		littleTool::readString(fin, s);
	}
	void write(fstream &fout) {
		littleTool::writeString(fout, s);
	}
	operator string () {
		return s;
	}
};

class MyInt {
public:
	int t;
	MyInt(int _t = 0): t(_t) {}
	void read(fstream &fin) {
		fin.read(reinterpret_cast<char *> (&t), sizeof t);
	}
	void write(fstream &fout) {
		fout.write(reinterpret_cast<const char *> (&t), sizeof t);
	}
	operator int () {
		return t;
	}
};
	
class Time {
public:
	int year, month, day, hour, min;

	Time(int _year = 2017, int _month = 0, int _day = 0, int _hour = 0, int _min = 0): year(_year), month(_month), day(_day), hour(_hour), min(_min) {}

	const static size_t SIZE = 5 * sizeof(int);
	Time(const string &Date){
		int tmp = 0, pos = 0, len = Date.length();
		while(pos < len && Date[pos] >= '0' && Date[pos] <= '9'){
			tmp *= 10; tmp += Date[pos] - '0';
		}
		_year = tmp; tmp = 0;
		pos ++;
		while(pos < len && Date[pos] >= '0' && Date[pos] <= '9'){
			tmp *= 10; tmp += Date[pos] - '0';
		}
		_month = tmp; tmp = 0;
		++pos;
		while(pos < len && Date[pos] >= '0' && Date[pos] <= '9'){
			tmp *= 10; tmp += Date[pos] - '0';
		}
		_day = tmp;
		_hour = _min = -1;
	}
	friend bool operator < (const Time &a, const Time &b) {
		return (a.year == b.year ?
			    a.month == b.month?
			    a.day == b.day ?
			    a.hour == b.hour ?
			    a.min < b.min :
			    a.hour < b.hour :
			    a.day < b.day :
			    a.month < b.month :
			    a.year < b.year);
	}
	
	friend bool operator == (const Time &a, const Time &b) {
		return (a.year == b.year && a.month == b.month && a.day == b.day && a.hour == b.hour && a.min == b.min);
	}

	friend bool operator != (const Time &a, const Time &b) {
		return !(a == b);
	}

	friend int operator - (const Time &a, const Time &b) {
		if (a.month == b.month) return (b.day - a.day);
		return (b.day + 31 - a.day);
	}
	void Add(const string &Clock){
		_hour = ((Clock[0] - '0') * 10 + (Clock[1] - '0'));
		_min = ((Clock[3] - '0') * 10 + (Clock[4] - '0'));
	}
	void read(fstream &fin) {
		fin.read(reinterpret_cast<char *> (&year), sizeof year);
		fin.read(reinterpret_cast<char *> (&month), sizeof month);
		fin.read(reinterpret_cast<char *> (&day), sizeof day);
		fin.read(reinterpret_cast<char *> (&hour), sizeof hour);
	}
	
	void write(fstream &fout) const {
		fout.write(reinterpret_cast<const char *> (&year), sizeof year);
		fout.write(reinterpret_cast<const char *> (&month), sizeof month);
		fout.write(reinterpret_cast<const char *> (&day), sizeof day);
		fout.write(reinterpret_cast<const char *> (&hour), sizeof hour);
	}
};

const Time data0(2017, 3, 28, 0, 0);

class QueryInformation {
public:
	string st, ed, tr;
	QueryInformation() {}
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
		littleTool::readString(fin, st);
		littleTool::readString(fin, ed);
		littleTool::readString(fin, tr);
	}
	
	void write(fstream &fout) {
		littleTool::writeString(fout, st);
		littleTool::writeString(fout, ed);
		littleTool::writeString(fout, tr);
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
		fin.read(reinterpret_cast<char *>(&t), sizeof t);
	}
	
	void write(fstream &fout) {
		fout.write(reinterpret_cast<const char *>(&t), sizeof t);
	}
	
	friend ostream& operator << (ostream &fout, const UserInformation &a) {
		fout << a.t;
		return fout;
	}
};


/** 
  * xj
*/	
class ticket{
private:
    string start;
    string dest;
    int num;
    int trainid;
    int kind;
    Time date;
public:
	const static size_t SIZE = 20 * sizeof(char) + 3 * sizeof(int) + Time::SIZE;
    ticket(const string &s,const string &d,int n,int tid,int k,const Time &da):start(s),dest(d),num(n),trainid(tid),kind(k),date(da){}
    ticket(){
        start = dest = "";
        trainid = kind = -1;
        num = 0;
    }
    bool operator ==(const ticket &other){
        if (start != other.start) return false;
        if (dest != other.dest) return false;
        if (trainid != other.trainid) return false;
        if (kind != other.kind) return false;
        if (date != other.date) return false;
        return true;
    }
    void changenum(int k){
        if (num + k < 0) throw notEnoughTicket{};
        num+=k;
    }
    int getNum() const {
    	return num;
    }
    void read(fstream &fin){
        littleTool::readString(fin, start);
        littleTool::readString(fin, dest);
        fin.read(reinterpret_cast<char *>(&num), sizeof num);
        fin.read(reinterpret_cast<char *>(&trainid), sizeof trainid);
        fin.read(reinterpret_cast<char *>(&kind), sizeof kind);
        date.read(fin);
    }
     void write(fstream &fout) const {
        littleTool::writeString(fout, start);
        littleTool::writeString(fout, dest);
        fout.write(reinterpret_cast<const char *>(&num), sizeof num);
        fout.write(reinterpret_cast<const char *>(&trainid), sizeof trainid);
        fout.write(reinterpret_cast<const char *>(&kind), sizeof kind);
        date.write(fout);
    }
};

/** 
  * xj
*/
class User{
private:
    int id;
    string password;
    string name;
    list<ticket> Tic;
	static int pwdLength;
	static int unmLength;
	static int ticLength;
public:
	const static size_t SIZE = sizeof(int) + 40 * sizeof(char) + ticLength * ticket::SIZE; 
    User(int _id = -1, string userName = "", passWord = "000000"): id(_id){
        password = passWord;
        name = userName;
    }
    int getID() const{
        return id;
    }
    void modifyName(const string &x){
        name = x;
    }
    void modifyPswd(const string &x){
        password = x;
    }
    string getname() const{
        return name;
    }
    string getpass() const{
        return password;
    }
    
    size_t registe(char *inFile){
		size_t n;
		fstream fio(inFile);
		fio.seekg(0);
		fio.read(reinterpret_cast<char *>(&n),sizeof(n));
		fio.seekp(0);++n;
		fio.write(reinterpret_cast<const char *>(&n),sizeof(n));
		fio.seekp((n - 1) * User::Size,ios::cur);
		write(fio);
		return n;
	}
		
    void editticket(const string &s,const string &d,int n,int tid,int k,const Time &da){
    	if (n == 0) return;
        ticket a(s,d,n,tid,k,da);
        list<ticket>::iterator t = Tic.search(a);
        if (n < 0) {
        	if (t != Tic.end()){
           		t -> changenum(n);
            	if (t -> getNum() == 0) Tic.remove(t);
        	}
        	else  throw ticketNotExist{};
        }
        else {
        	if (t == Tic.end()) {
        		Tic.insert(0, a);
        	}
        	else t -> changenum(n);
        }
    }
    void read(fstream &fin){
        fin.read(reinterpret_cast<char *>(&id), sizeof id);
        littleTool::readString(fin, name);
		littleTool::readString(fin, password);
        Tic.read(fin);
    }
    void write(fstream &fout){
        fout.write(reinterpret_cast<const char *>(&id), sizeof id);
        littleTool::writeString(fout, name);
		littleTool::writeString(fout, password);
		Tic.write(fout);
    }
};

int User::unmLength = 20;
int User::pwdLength = 20;
int User::ticLength = 20;

/** 
  * wtl
*/
class Train {
	friend User;
	friend Admistration;
private:
	string Name; 
	int id; 
	list<string> ZhanTai;
	list<double> Price[10]; 
	list<int> Remain[30][10]; 
	bool Sell[30];
	list<Time> Arrival; 
	list<Time> Dapart; 
	list<int> Kilometer;

	const static int stateNum = 60;
public:
	const static size_t SIZE = sizeof(char) * 12 // train name 	
							 + sizeof(int) //id: saving position
							 + (sizeof(char) * 10 + Time::SIZE * 2 + sizeof(int)) * stateNum // train station, arrival time, dapart and kilometer
							 + sizeof(double) * stateNum * 10 // price
							 + sizeof(int) * stateNum * 10 * 30 // remain 
							 + sizeof(bool) * 30; // whether is selling

	void read(fstream &fin) {
		littleTool::readString(Name);
		fin.read(reinterpret_cast<char *> (&id), sizeof id);
		ZhanTai.read(fin);
		for (int j = 0; j < 10; ++j)
			Price[i][j].read(fin);
		for (int i = 0; i < 30; ++i) 
			for (int j = 0; j < 10; ++j)
				Remain[i][j].read(fin);
		for (int i = 0; i < 30; ++i) {
			fin.read(reinterpret_cast<char *> (&Sell[i]), sizeof(bool));
		}
		Arrival.read(fin);
		Dapart.read(fin);
		Kilometer.read(fin);
	}
	
	void write(fstream &fout) {
		littleTool::writeString(Name);
		fout.write(reinterpret_cast<const char *> (&Sell[i]), sizeof(bool);
		ZhanTai.write(fout);
		for (int j = 0; j < 10; ++j)
			Price[j].write(fout);
		for (int i = 0; i < 30; ++i)
			for (int j = 0; j < 10; ++j)
				Remain[i][j].write(fout);
		for (int i = 0; i < 30; ++i) {
			fout.write(reinterpret_cast<const char *> (&id), sizeof id);
		}
		Arrival.write(fout);
		Dapart.write(fout);
		Kilometer.write(fout);
	}

	
};


class logClass {
	
public:
	void insertLog() {
		
	}
	
	void eraseLog() {
		
	}
	
	void modifyLog() {
	
	}
	
};

#endif
