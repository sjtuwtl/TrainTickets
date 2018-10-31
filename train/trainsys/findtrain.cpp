#include <sstream>
#include "TrainClass.hpp"
#include "toolSet.hpp"
#include "varset.h"

using std::ostringstream;
using std::string;

string Train::getInfo(const string &start, const string &dest, const string &datString) const {
    string res = Name + ' ';
    int p, q;
    for (p = 0; p < size && ZhanTai[p] != start; ++p);
    for (q = p; q < size && ZhanTai[q] != dest; ++q);
    res += start + ' ' + Dapart[p] + ' ';
    res += dest + ' ' + Arrival[p] + ' ';

    int t = 0;
    for (int i = 0; i < 10; ++i) {
        double sum = 0.0;
        for (int j = p; j <= q; ++j) sum += littleTool::str2Dou(Price[i][j]);
        if (sum > 1e-5) {
            res += littleTool::reMatch(i) + ' ';
            ++t;
            res += littleTool::dou2Str(sum) + ' ';
        }
    }
    if (t < 3) {
        res += "- - ";
    }
    return res;
}

string Enquiry(string start, string target, string datString) {
    TMAP::iterator it, a, b;
    Train train;
    string res;
    a = trainMap.lower_bound(QueryInformation(start, target, "A0"));
    b = trainMap.upper_bound(QueryInformation(start, target, "Z9999")); --b;

    for (it = a; it != b; it++) {
        train = trainList[it -> second];
        res += train.getInfo(start, target, datString);
        //show();
    }
    return res;

}
