#ifndef __LITTLE_TOOL__
#define __LITTLE_TOOL__
#include <string>
#include <fstream>

using std::fstream;
using std::string;

namespace littleTool {
    void readString(fstream &fin, string &str);
    void writeString(fstream &fout, string str);

    double str2Dou(string str);
    string dou2Str(double x);
    string id2String(int x, int len);
    int string2Int(const string &str);
    string int2String(int x);

    int matchSeat(string ticketClass);
    string reMatch(int x);
    void optWithString(string &t);
}

#endif
