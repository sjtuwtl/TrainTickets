#ifndef __TICKET___
#define __TICKET__

#include "linkList.hpp"

class ticket{
private:
    string start;
    string dest;
    int num;
    string trainid;
    string kind;
    string date;
public:
	const static size_t SIZE = 100 * sizeof(char) + sizeof(int);
    ticket(const string &s,const string &d,int n,const string &tid, const string &k,const string &da):
    	start(s),dest(d),num(n),trainid(tid),kind(k),date(da){
			littleTool::optWithString(start);
			littleTool::optWithString(dest);
			littleTool::optWithString(trainid);
			littleTool::optWithString(date);
		}
    ticket(){}
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
        littleTool::readString(fin, trainid);
        littleTool::readString(fin, kind);
        littleTool::readString(fin, date);
    }
     void write(fstream &fout) const {
        littleTool::writeString(fout, start);
        littleTool::writeString(fout, dest);
        fout.write(reinterpret_cast<const char *>(&num), sizeof num);
        littleTool::writeString(fout, trainid);
        littleTool::writeString(fout, kind);
        littleTool::writeString(fout, date);
    }
    void testPrint() {
    	cout << start << ' ' << dest << ' ' << num << ' ' << trainid << ' ' << kind << ' ' << date << endl;
    }
};

#endif
