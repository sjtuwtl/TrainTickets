#ifndef __USER__
#define __USER__

#include <vector>
#include <string>
#include "TicketClass.hpp"
#include "TrainClass.hpp"
using std::vector;
using std::string;

class User{
private:
    int id;
    bool admin;
    string name;
	string password;
    vector<ticket> Tic;
	const static int pwdLength = 20;
	const static int unmLength = 20;
	const static int ticLength = 20;
public:

    User(int _id = -1, string userName = "", string passWord = "000000", bool flag = 0):
        id(_id), name(userName), password(passWord), admin(flag) {
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

    bool isAdmin() const {return admin;}
    
    void editticket(const string &s,const string &d,int n,const Train &train, const string &k,const string &da){
    	if (n == 0) return;

        string startTime, destTime;
        double singlePrice = train.getPriceAndTime(s, d, k, startTime, destTime);

        ticket a(s, startTime, d, destTime, n, train.getName(), k, da);
        vector<ticket>::iterator t;
		for (t = Tic.begin(); t != Tic.end(); ++t) {
			if (*t == a) break;
		}

        if (n < 0) {
        	if (t != Tic.end()){
                t -> changenum(n, singlePrice);
            	if (t -> getNum() == 0) {
                    std::swap(*t, *(Tic.end() - 1));
					Tic.pop_back();
				}
        	}
        	else  {
				throw ticketNotExist{};
			}
        }
        else {
        	if (t == Tic.end()) {
        		Tic.push_back(a);
        	}
            else t -> changenum(n, singlePrice);
        }
    }

    string queryTicket();

    void read(fstream &fin){
            fin >> id >> admin >> name >> password;
            size_t sz;
            fin >> sz;
            for (int i = 0; i < sz; ++i) {
                ticket tmp;
                tmp.read(fin);
                Tic.push_back(tmp);
            }
        }
        void write(fstream &fout){
            fout << id << ' ';
            fout << admin << ' ';
            fout << name << ' ' << password << ' ';
            size_t sz = Tic.size();
            fout << sz << ' ';
            for (int i = 0; i < sz; ++i) {
                Tic[i].write(fout);
            }
        }
};

string trueRegister(const string &s1, const string &s2, bool is_admin);

int login(const string &userid, const string &password, bool flag);

void changeInfo(string userName = "", string userPass = "");

void ticketUsrOpt(const  string &UsrOpt, const  string &TicketNum, const  string &TicketClass, const  string &TrainId, const  string &Start, const  string &Target, const  string &Date);

#endif
