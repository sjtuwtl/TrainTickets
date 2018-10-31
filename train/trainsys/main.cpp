#include "loginwindows.h"
#include <QApplication>

#include "classSet2.hpp"
#include "TrainClass.hpp"
#include "UserClass.hpp"
#include "initopt.hpp"

typedef MyMap<QueryInformation> TMAP;
typedef MyMap<UserInformation> UMAP;

const char TrainFile[] = "E:\\interface\\newFile\\transys\\trainsys\\Train.inf";
const char UserFile[] = "E:\\interface\\newFile\\transys\\trainsys\\User.inf";
const char TrainTree[] = "E:\\interface\\newFile\\transys\\trainsys\\traintree.in";
const char UserTree[] = "E:\\interface\\newFile\\transys\\trainsys\\UserTree.config";
const char TrainLog[] = "E:\\interface\\newFile\\transys\\trainsys\\TrainOpt.log";

TMAP trainMap;
UMAP userMap;

vector<Train> trainList;
vector<User> userList;
vector<logClass> userLog;
User *curUser;
logClass *curLog;
logClass sysLog(TrainLog);

void test1() {
    const char checi[] = "E:\\interface\\newFile\\transys\\trainsys\\checi.out";
    readUpdFile(checi);					//split the information in the train data and add the train in Train.inf
    buildTrain(TrainFile);	//build the map from (start, target, trainId) to the position in the file
    outTrainTree(TrainTree);		//write the tree in the TrainTree.config
    outTrainList();
    fstream file(TrainFile, fstream::in);
    initUserFile(UserFile, UserTree);
}

int main(int argc, char *argv[])
{/*
    inTrainTree(TrainTree, trainMap);		//read the trainMap
    inTrainList();

    inUserTree(UserTree, userMap);			//read the userMap

    inUserList();
    int t1 = trainList.size(), t2 = trainMap.size(), u1 = userList.size(), u2 = userMap.size();*/
    QApplication a(argc, argv);
    loginWindows w;
    w.show();
/*
    outTrainTree(TrainTree);
    outUserTree(UserTree, userMap);
    outUserList();
    outTrainList();
    return a.exec();

    test1();
    */
    return a.exec();
}
