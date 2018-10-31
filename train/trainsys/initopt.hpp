#ifndef INITOPT_HPP
#define INITOPT_HPP

#include <cstring>
#include <string>

using std::string;
using std::fstream;
using std::ifstream;
using std::vector;
using std::ios;
using std::istringstream;

#include "varset.h"

void inTrainTree(const char *inFile, TMAP &mp);
void outTrainTree(const char *outFile);
void inUserTree(const char *inFile, UMAP &mp);
void outUserTree(const char *outFile, const UMAP &mp);
void inUserList();
void outUserList();
void inTrainList();
void outTrainList();
int divideString(string inString,  string *res, char divSymbol);
void readUpdFile(const char inFile[]);
void buildTrain(const char *inFile);
void initUserFile(const char *userFile, const char *userTree);

void ticketOpt( string *list, const TMAP &trainMap, UMAP &userMap, const char *userFile);
void readOptFile(const char *inFile);
void ticketUsrOpt(const  string &UsrName, const  string &UsrId, const  string &UsrOpt, const  string &TicketNum, const  string &TicketClass, const  string &TrainId, const  string &Start, const  string &Target, const  string &Date);



#endif // INITOPT_HPP
