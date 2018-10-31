#ifndef VARSET_H
#define VARSET_H

#include "classSet2.hpp"
#include "map.hpp"
#include <vector>
#include "TrainClass.hpp"
#include "UserClass.hpp"
#include "logclass.h"

using std::vector;

typedef MyMap<QueryInformation> TMAP;
typedef MyMap<UserInformation> UMAP;

extern const char TrainFile[];
extern const char UserFile[];
extern const char TrainTree[];
extern const char UserTree[];
extern const char TrainLog[];

extern TMAP trainMap;
extern UMAP userMap;

extern vector<Train> trainList;
extern vector<User> userList;
extern vector<logClass> userLog;

extern User *curUser;
extern logClass *curLog;
extern logClass sysLog;

#endif // VARSET_H
