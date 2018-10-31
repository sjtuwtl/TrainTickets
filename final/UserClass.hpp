#ifndef __USER__
#define __USER__
class User{
private:
    int id;
    string name;
	string password;
    vector<ticket> Tic;
	const static int pwdLength = 20;
	const static int unmLength = 20;
	const static int ticLength = 20;
public:
	const static size_t SIZE = sizeof(int) * 3 + 40 * sizeof(char) + ticLength * ticket::SIZE; 
		
	void testPrint() {
		cout << "ID: " << id << endl;
		cout << "name: " << name << endl;
		cout << "password: " << password
		<< endl;
		cout << "ticket: " << endl;
		for (vector<ticket>::iterator it = Tic.begin(); it != Tic.end(); ++it) {
			it -> testPrint();
		}
	}

    User(int _id = -1, string userName = "", string passWord = "000000"):
		id(_id), name(userName), password(passWord) {
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
    
    size_t registe(const char *inFile){
		size_t n;
		fstream fio(inFile);
		fio.seekg(0);
		fio.read(reinterpret_cast<char *>(&n),sizeof(n));
		fio.seekp(0);++n;
		fio.write(reinterpret_cast<const char *>(&n),sizeof(n));
		fio.seekp((n - 1) * User::SIZE,ios::cur);
		write(fio);
		return n;
	}
    
    void editticket(const string &s,const string &d,int n,const string &tid, const string &k,const string &da){
    	if (n == 0) return;
        ticket a(s,d,n,tid,k,da);
        vector<ticket>::iterator t;
		for (t = Tic.begin(); t != Tic.end(); ++t) {
			if (*t == a) break;
		}
        if (n < 0) {
        	if (t != Tic.end()){
           		t -> changenum(n);
            	if (t -> getNum() == 0) {
					swap(*t, *(Tic.end() - 1));
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
        	else t -> changenum(n);
        }
    }
    void read(fstream &fin){
        fin.read(reinterpret_cast<char *>(&id), sizeof id);
        littleTool::readString(fin, name);
		littleTool::readString(fin, password);
		size_t sz;
		fin.read(reinterpret_cast<char *>(&sz), sizeof sz);
        for (int i = 0; i < sz; ++i) {
			ticket tmp;
			tmp.read(fin);
			Tic.push_back(tmp);
		}
    }
    void write(fstream &fout){
        fout.write(reinterpret_cast<const char *>(&id), sizeof id);
        littleTool::writeString(fout, name);
		littleTool::writeString(fout, password);
		size_t sz = Tic.size();
        for (int i = 0; i < sz; ++i) {
			Tic[i].write(fout);
		}
    }
};
#endif
