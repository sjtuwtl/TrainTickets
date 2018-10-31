#ifndef VIPFUNC_H
#define VIPFUNC_H
#include <fstream>
#include "logclass.h"
#include "exceptions.hpp"

using std::string;
using std::fstream;

void insertTrain(const Train &train);

bool insertTrain(const string &name, string *title, int titleLen, string list[][15], int listLen);

int delTrain(const string &trainId);

int changeTrain(const string &name, string *title, int titleLen, string list[][15], int listLen);

bool updateSell(const string &trainId, const string &date, bool flag);

void seeUser(int userid, string &text1, string &text2, string &text4);

string checkLog();

#endif // VIPFUNC_H
