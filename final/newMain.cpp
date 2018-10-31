#include <cstdio>
#include <iostream>
#include <fstream>
#include <sstream>
#include <cstring>
#include <string>
#include <vector> 
#include "utility.hpp"
using namespace std;

#include "map.hpp"

#include "toolSet.hpp"
#include "classSet2.hpp"

typedef MyMap<QueryInformation> TMAP;
typedef MyMap<UserInformation> UMAP;

#include "TrainClass.hpp"

const char TrainFile[] = "Train.inf";
const char UserFile[] = "User.inf";
const char TrainTree[] = "TrainTree.config";
const char UserTree[] = "UserTree.config";
const char TrainLog[] = "TrainOpt.log"; 

TMAP trainMap;

vector<Train> trainList;

inline int divideString(string inString, string *res, char divSymbol);

void inTrainList();
void outTrainList();
void inUserList();
void outUserList();

inline void readUpdFile(char inFile[]);
void readOptFile(const char *inFile);

inline void buildTrain(const char *inFile);

void inTrainTree(const char *inFile, TMAP &mp);
void outTrainTree(const char *outFile);
void inUserTree(const char *inFile, UMAP &mp);
void outUserTree(const char *outFile, const UMAP &mp);

void initUserFile(const char *userFile, const char *userTree);
void modifyTicket(const string &start, const string &target, const string &trainNum, const string &dateString, const string &DangWei, int ticketNum, const TMAP &TrainMap);

void ticketOpt(string *list, const TMAP &trainMap, UMAP &userMap, const char *userFile);

int main() {
	inTrainTree(TrainTree, trainMap);		//read the trainMap
	inUserTree(UserTree, userMap);			//read the userMap 
	inTrainList();
	inUserList();
	
	
	
	outTrainTree(TrainTree);
	outUserTree(UserTree, userMap);	
	outUserList();
	outTrainList();
	return 0;
}
