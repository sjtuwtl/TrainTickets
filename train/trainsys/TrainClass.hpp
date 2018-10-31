#ifndef __TRAIN__
#define __TRAIN__

#include <fstream>
#include <string>
#include "toolSet.hpp"
#include "classSet2.hpp"
#include "map.hpp"

typedef MyMap<QueryInformation> TMAP;

using std::string;
using std::fstream;

class logClass;

class Train {
//	friend User;
    friend logClass;
    friend bool operator == (const Train &a, const Train &b) {
        return a.Name == b.Name;
    }

private:
	string Name; 
	int id, size; 
	string ZhanTai[70];
	string Price[10][70]; 
	int Remain[31][10][70]; 
	bool Sell[31];
	string date[70];
	string Arrival[70]; 
	string Dapart[70]; 
	string Kilometer[70];

public:
	const static size_t SIZE = 57206;
	
	Train() {}
	
	Train(const string &name, string *title, int titleLen, string list[][15], int listLen, int _id) {
		Name = name;
		id = _id;
		size = listLen;
		
		for (int i = 0; i < 10; ++i) {
			for (int j = 0; j < 70; ++j) {
				for (int k = 0; k < 31; ++k) Remain[k][i][j] = 0;
				Price[i][j] = "¥0";
			}
		}
		
		for(int i = 0; i < size; ++ i){
			ZhanTai[i] = list[i][0];
			date[i] = list[i][1];
			Arrival[i] = list[i][2];
			Dapart[i] = list[i][3];
			Kilometer[i] = list[i][4];
		
			for(int j = 5; j < titleLen; ++ j){
				int seat = littleTool::matchSeat(title[j]);
				Price[seat][i] = list[i][j];
				for (int k = 0; k < 31; ++k) {
					Remain[k][seat][i] = 2000;
				}
			}
		}
		
		for (int i = 0; i < 31; ++i) Sell[i] = 1;
	}

    string getName() const {
        return Name;
    }

    void testPrint() {
        for (int i = 0; i < size; ++i) printf("%s ", ZhanTai[i].c_str());
        puts("");
    }

	void read(fstream &fin) {
        fin >> Name;
        fin >> id;
        fin >> size;
        for (int i = 0; i < 31; ++i) {
            for (int j = 0; j < 10; ++j) {
                for (int k = 0; k < size; ++k) Remain[i][j][k] = 0;
            }
        }
        for (int i = 0; i < size; ++i) {
            fin >> ZhanTai[i];
        }
        for (int i = 0; i < 10; ++i) {
            for (int j = 0; j < size; ++j) {
                fin >> Price[i][j];
            }
        }
        for (int i = 0; i < 31; ++i)
            for (int j = 0; j < 10; ++j)
                for (int k = 0; k < size; ++k)
                    fin >> Remain[i][j][k];
        for (int i = 0; i < 31; ++i) fin >> Sell[i];
        for (int i = 0; i < size; ++i)
            fin >> date[i];
        for (int i = 0; i < size; ++i)
            fin >> Arrival[i];
        for (int i = 0; i < size; ++i)
            fin >> Dapart[i];
        for (int i = 0; i < size; ++i)
            fin >> Kilometer[i];
	}
	
    void write(fstream &fout) {
        fout << Name << ' ';
        fout << id << ' ';
        fout << size << ' ';
        for (int i = 0; i < 31; ++i) {
            for (int j = 0; j < 10; ++j) {
                for (int k = 0; k < size; ++k) Remain[i][j][k] = 0;
            }
        }
        for (int i = 0; i < size; ++i) {
            fout << ZhanTai[i] << ' ';
        }
        for (int i = 0; i < 10; ++i) {
            for (int j = 0; j < size; ++j) {
                fout << Price[i][j] << ' ';
            }
        }
        for (int i = 0; i < 31; ++i)
            for (int j = 0; j < 10; ++j)
                for (int k = 0; k < size; ++k)
                    fout << Remain[i][j][k] << ' ';
        for (int i = 0; i < 31; ++i) fout << Sell[i] << ' ';
        for (int i = 0; i < size; ++i)
            fout << date[i] << ' ';
        for (int i = 0; i < size; ++i)
            fout << Arrival[i] << ' ';
        for (int i = 0; i < size; ++i)
            fout << Dapart[i] << ' ';
        for (int i = 0; i < size; ++i)
            fout << Kilometer[i] << ' ';
	}
	
    void inTree(TMAP &mp) const {
		for (int i = 0; i < size; ++i) {
			for (int j = i + 1; j < size; ++j) {
				mp[QueryInformation(ZhanTai[i], ZhanTai[j], Name)] = id;
			}
		}
	}

    void outTree(TMAP &mp) const {
        for (int i = 0; i < size; ++i) {
            for (int j = i + 1; j < size; ++j) {
                TMAP::iterator it = mp.find(QueryInformation(ZhanTai[i], ZhanTai[j], Name));
                if (it == mp.end()) throw -1;
                else mp.erase(it);
            }
        }
    }
	
    bool checkRemain(const string &start, const string &target, int delTicket, const Time &date, int k) const {
		int i = 1, j;
		while (i < size && ZhanTai[i] != start) i++;
		for (j = i + 1; j < size && ZhanTai[j] != target ; j++) 
			if (Remain[date - date0][k][j] - delTicket < 0) return false;
		return true;
	}
	
	void modifyRemain(const string &start, const string &target, int delTicket, const Time &date, int k) {
		int i = 1, j;
		while (i < size && ZhanTai[i] != start) i++;
		for (j = i; j < size && ZhanTai[j] != target ; j++) {
			Remain[date - date0][k][j] -= delTicket;
		}
	}

    string getInfo(const string &start, const string &dest, const string &dateString) const ;

    double getPriceAndTime(const string &start, const string &dest, const string &kind, string &sTime, string &tTime) const {
        int p, q, k = littleTool::matchSeat(kind);
        for (p = 0; p < size && !(ZhanTai[p] == start); ++p);
        double sum = 0;
        for (q = p; q < size && !(ZhanTai[q] == dest) ; ++q) {
            sum += littleTool::str2Dou(Price[k][q]);
        }
        sTime = Dapart[p];
        tTime = Arrival[q];
        return sum;
    }

    bool beSold(const string &date) {
        int k = date - date0;
        for (int i = k; i < size; ++i) if (Sell[i]) return true;
        return false;
    }

    void setSold(const string &date, bool flag) {
        int k = date - date0;
        for (int i = k; i < size; ++i) {
            Sell[i] = flag;
        }
    }
};

string Enquiry(string start, string target, string datString);

const Train &modifyTicket(const string &start, const string &target, const string &trainNum, const string &dateString, const  string &DangWei, int ticketNum, const TMAP &TrainMap);
#endif

