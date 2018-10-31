#ifndef __LITTLE_TOOL__
#define __LITTLE_TOOL__

namespace littleTool {
	void readString(fstream &fin, string &str) {
		size_t len = 1;
		fin.read(reinterpret_cast<char *>(&len), sizeof len);
		if (!len) {	
			return;
		}
		char tmp[len + 1];
		fin.read(tmp, len);
		tmp[len] = 0;
		str = tmp;
	}
	
	void writeString(fstream &fout, string str) {
		size_t len = str.length();
		char tmp[len + 1];
		strcpy(tmp, str.c_str());
		if (tmp[len - 1] == '\n' || tmp[len - 1] == '\t' || tmp[len - 1] == '\r') len--;
		fout.write(reinterpret_cast<const char *> (&len), sizeof len);
		if (!len) {
			return;
		}
		fout.write(tmp, len);
	}
	
	double str2Dou(string str) {
		double x = 0;
		int i;
		for (i = 1; i < str.length() && str[i] != '.'; ++i) {
			x = x * 10 + (str[i] - '0');
		}
		
		double base = 0.1;
		for (++i; i < str.length(); ++i) {
			x = x + 1.0 * (str[i] - '0') * base;
			base *= 0.1;
		}

		return x;
	}
	string id2String(int x, int len) {
		string str;
		for (int i = len - 1; i >= 0; i--) {
			str[i] = x % 10;
			x /= 10;
		}
		return str;
	}
	
	int string2Int(const string &str) {
		int res = 0;
		for (int i = 0; i < str.length(); ++i) {
			res = res * 10 + str[i] - '0';
		}
		return res;
	}

	int matchSeat(string ticketClass) {
		if (ticketClass.back() == '\t' || ticketClass.back() == '\n' || ticketClass.back() == '\r') ticketClass.erase(ticketClass.end() - 1);
		if (ticketClass == "一等座") return 0;
		if (ticketClass == "二等座") return 1;
		if (ticketClass == "商务座") return 2;
		if (ticketClass == "无座") return 3;
		if (ticketClass == "硬座") return 4;
		if (ticketClass.find("软卧") != string::npos && ticketClass != "高级软卧") return 5;
		if (ticketClass == "特等座") return 6;
		if (ticketClass == "高级软卧") return 7;
		if (ticketClass == "软座") return 8;
		if (ticketClass.find("硬卧") != string::npos) return 9;
	}
	void optWithString(string &t) {
		if (t.back() == '\r' || t.back() == '\t' || t.back() == '\n') t.erase(t.end() - 1);
	}
}

#endif
