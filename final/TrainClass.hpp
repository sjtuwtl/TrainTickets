#ifndef __TRAIN__
#define __TRAIN__
class Train {
//	friend User;
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

	void read(fstream &fin) {
		littleTool::readString(fin, Name);
		fin.read(reinterpret_cast<char *> (&id), sizeof id);
		fin.read(reinterpret_cast<char *> (&size), sizeof size);
		for (int i = 0; i < 31; ++i) {
			for (int j = 0; j < 10; ++j) {
				for (int k = 0; k < size; ++k) Remain[i][j][k] = 0;
			}
		}
		for (int i = 0; i < size; ++i) {
			littleTool::readString(fin, ZhanTai[i]);
		}
		for (int i = 0; i < 10; ++i) {
			for (int j = 0; j < size; ++j) {
				littleTool::readString(fin, Price[i][j]);
			}
		}
		for (int i = 0; i < 31; ++i) 
			for (int j = 0; j < 10; ++j)
				fin.read(reinterpret_cast<char *>(Remain[i][j]), sizeof(int) * size);
		fin.read(reinterpret_cast<char *>(Sell), sizeof(bool) * 31);
		for (int i = 0; i < size; ++i)
			littleTool::readString(fin, date[i]);
		for (int i = 0; i < size; ++i)
			littleTool::readString(fin, Arrival[i]);
		for (int i = 0; i < size; ++i)
			littleTool::readString(fin, Dapart[i]);
		for (int i = 0; i < size; ++i)
			littleTool::readString(fin, Kilometer[i]);
	}
	
	void write(fstream &fout) {
		littleTool::writeString(fout, Name);
		fout.write(reinterpret_cast<const char *> (&id), sizeof id);
		fout.write(reinterpret_cast<const char *> (&size), sizeof size);
		for (int i = 0; i < size; ++i) {
			littleTool::writeString(fout, ZhanTai[i]);
		}
		for (int i = 0; i < 10; ++i) {
			for (int j = 0; j < size; ++j) {
				littleTool::writeString(fout, Price[i][j]);
			}
		}
		
		for (int i = 0; i < 31; ++i) 
			for (int j = 0; j < 10; ++j)
				fout.write(reinterpret_cast<const char *>(Remain[i][j]), sizeof(int) * size);
		fout.write(reinterpret_cast<const char *>(Sell), sizeof(bool) * 31);
		for (int i = 0; i < size; ++i)
			littleTool::writeString(fout, date[i]);
		for (int i = 0; i < size; ++i) 
			littleTool::writeString(fout, Arrival[i]);
		for (int i = 0; i < size; ++i)
			littleTool::writeString(fout, Dapart[i]);
		for (int i = 0; i < size; ++i)
			littleTool::writeString(fout, Kilometer[i]);
	}
	
	size_t getsize() {
		size_t res = 0;
		res += Name.length() * sizeof(char);
		res += sizeof(size_t);
		res += sizeof(int) * 2;
		for (int i = 0; i < size; ++i) {
			res += ZhanTai[i].length() * sizeof(char);
			res += sizeof(size_t);
		}
		for (int i = 0; i < 10; ++i) {
			for (int j = 0; j < size; ++j) {
				res += Price[i][j].length() * sizeof(char);
				res += sizeof(size_t);
			}
		}
		
		for (int i = 0; i < 31; ++i) 
			for (int j = 0; j < 10; ++j)
				res += sizeof(int) * size;
		res += sizeof(bool) * 31;
		for (int i = 0; i < size; ++i) {
			res += date[i].length() * sizeof(char);
			res += sizeof(size_t);
		}
		for (int i = 0; i < size; ++i) {
			res += Arrival[i].length() * sizeof(char);
			res += sizeof(size_t);
		}
		for (int i = 0; i < size; ++i) {
			res += Dapart[i].length() * sizeof(char);
			res += sizeof(size_t);
		}
		for (int i = 0; i < size; ++i) {
			res += Kilometer[i].length() * sizeof(char);
			res += sizeof(size_t);
		}
		return res;
	}
	
	void testPrint() {
		cout << "Name: " << Name << endl;
		cout << "id: " << id << endl;
		cout << "ZhanTai: " << endl;
		for (int i = 0; i < size; ++i) {
			cout << ZhanTai[i] << ' ';
		}
		cout << endl;
		cout << "Price: " << endl;
		for (int i = 0; i < 10; ++i) {
			cout << "kind " << i << ":" << endl;	
			for (int j = 0; j < size; ++j) {
				cout << Price[i][j] << ' ' ;
			}
			cout << endl;
			cout << "Remain: " << endl;
			for (int j = 0; j < 31; ++j) {
				cout << "day " << j << ':' << endl;
				for (int k = 0; k < size; ++k) {
					cout << Remain[j][i][k] << ' ';
				}
				cout << endl;
			}
			cout << endl;
		}
		cout << endl;
	}
	
	void inTree(TMAP &mp) {
		for (int i = 0; i < size; ++i) {
			for (int j = i + 1; j < size; ++j) {
				mp[QueryInformation(ZhanTai[i], ZhanTai[j], Name)] = id;
			}
		}
	}
	
	bool checkRemain(const string &start, const string &target, int delTicket, const Time &date, int k) {	
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
};
#endif

