#include <cstdio>
#include <iostream>
#include <fstream>
#include <sstream>
#include <cstring>
#include "map.hpp"
using namespace std;

#include "classSet.hpp"
#include "trainClass.hpp"
#include "userClass.hpp"

const char TrainFile[] = "Train.inf"
const char UserFile[] = "User.inf"
const char TrainTree[] = "TrainTree.config"
const char UserTree[] = "UserTree.config"
const char TrainLog[] = "TrainOpt.log"

typedef MyMap<QueryInformation> TMAP;
typedef MyMap<MyInt> UMAP;

void readUpdFile(char *inFile);
void readOptFile(char *inFile);

void inTrainTree(char *inFile, TMAP &mp);
void inUserTree(char *infile, User &mp);
void outTrainTree(char *outFile, const TMAP &mp);
void outUserTree(char *outFile, const UMAP &mp);

void initUserFile();

int divideString(string inString, string *res, char divSymbol) {
	istringstream sin(inString);
	int len = 0;
	for (len = 0; getline(sin, res[len], divSymbol); ++len);
	return len;
}

int main(int argc, char *argv[]) {

	TMAP trainMap;
	UMAP userMap;
	
	if (argc == 1 || strcmp(argv[1], "--help") == 0) {
		cout << "-upd	To input the initiative train information" << '\n';
		cout << "-opt	To test the operation of tickets for the passangers" << '\n';
	}
	else if (strcmp(argv[1], "-upd") == 0) {
		readUpdFile(argv[2]);					//split the information in the train data and add the train in Train.inf 
		buildTrainTree(TrainFile, trainMap);	//build the map from (start, target, trainId) to the position in the file
		outTrainTree(TrainTree, trainMap);		//write the tree in the TrainTree.config
		initUserFile(UserFile, UserTree);		//add a empty node in the UserTree.config and add the init size(0) in the User.inf 
	}
	else if (strcmp(argv[1], "-opt") == 0) {
		inTrainTree(TrainTree, trainMap);		//read the trainMap
		inUserTree(UserTree, userMap);			//read the userMap 
		readOptFile(argv[2], trainMap, userMap);//split the information in the data and call the ticket operation.
		outUserTree(UserTree, userMap);			//write the userMap, and needn't to deal with th trainMap.
	}
	else {
		cout << "Sorry, there is no operation named " << argv[1] << ".\n";
	}
	
}

/*
	add a "0" to the UserFile.inf and add a empty node to the UserTree
*/
void initUserFile(char *userFile, char *userTree) {
	int x = 0, y = -1;
	size_t size = 0;
	fstream outFile(userFile, fstream::out);
	outFile.write(reinterpret_cast<const char *> (&size), sizeof size);
	fstream outTree(userTree, fstream::out);
	outFile.write(reinterpret_cast<const char *> (&x), sizeof x);
	outTree.write(reinterpret_cast<const char *> (&x), sizeof x);
	outTree.write(reinterpret_cast<const char *> (&y), sizeof y);
	outTree.write(reinterpret_cast<const char *> (&x), sizeof x);
}

void readUpdFile(char *inFile) {
	ifstream Uin(inFile);
	string trg, trc, tmp, title[15], list[110][15];
	do {
		if (!getline(Uin, trg, '/')) break;
		getline(Uin, trc);
		do {
			getline(Uin, tmp);
			int n = divideString(tmp, title), len = 0;
			
			while (true) {
				getline(Uin, tmp);
				int m = divideString(tmp, list[len], ',');
				for (int j = 0; j < m; ++j) {
					if (list[len++][j] == "终到站") break;
				}
			}
			
			addTrain(title, n, list, len); //add a train with the lable title and station list
		
		} while (true);
		
	}while (true);
	Uin.close();
}

void readOptFile(char *inFile,TMAP &trainMap, UMAP &userMap) {
	ifstream Oin(inFile);
	
	string tmp, list[14];
	
	while (getline(Oin, tmp)) {
		int len = divideString(tmp, list, ' ');
		ticketOpt(list, trainMap, userMap, UserFile);
	}

	Oin.close();
}

void inTrainTree(char *inFile, TMAP &mp) {
	fstream fin(inFile, fstream::in);
	mp.read(fin);
	fin.close();
}

void inUserTree(char *inFile, UMAP &mp) {
	fstream fin(inFile, fstream::in);
	mp.read(fin);
	fin.close();
}

void outTrainTree(char *outFile, const TMAP &mp) {
	fstream fout(outFile, fstream::out | ios_base::trunc);
	mp.write(fout);
	fout.close();
}
void outUserTree(char *outFile, const UMAP &mp) {
	fstream fout(outFile, fstream::out | ios_base::trunc);
	mp.write(fout);
	fout.close();
}

