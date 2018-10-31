#ifndef __LITTLE_TOOL__
#define __LITTLE_TOOL__

namespace littleTool {
	void readString(fstream &fin, string &str) {
		size_t len;
		fin.read(reinterpret_cast<char *>(&len), sizeof len);
		char tmp[len + 1];
		fin.read(tmp, len);
		tmp[len] = 0;
		str = tmp;
	}
	
	void writeString(fstream &fout, const string &str) {
		size_t len = str.length();
		fout.write(reinterpret_cast<const char *> (&len), sizeof len);
		fout.write(str.c_str(), len);
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
}

#endif
