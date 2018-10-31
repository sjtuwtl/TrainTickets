#include <cstdio>
#include <iostream>
#include <fstream>
#include <sstream>
#include <cstring>
#include <map>
using namespace std;

#include "classSet.hpp"
#include "trainClass.hpp"
#include "userClass.hpp"

typedef MyMap<QueryInformation> TMAP;
typedef MyMap<int> UMAP;


/** nh
  * 本函数要完成买票退票操作，需要判一下如果用户id在map里面没有，要加一个进去(文件、userMap)
  * list是输入文件里的一条记录，关键信息位置已标出，enum里面的元素可直接当成数组下标
  * 涉及到火车修改， 可调用如下函数：
*/
void ticketOpt(string *list, const TMAP &trainMap, UMAP &userMap, char *userFile) {
	enum userList{UsrName, UsrId, UsrOpt, TicketNum, TicketClass, TrainId = 7, Start = 9, Target = 11, Date = 13};
	int Id = 0, len = list[UsrId].length(),  pos;
	size_t size;
	for(int i = 0; i < len; ++ i){
		Id *= 10;
		Id += list[UsrId][i];
	}
	if(userMap.find(Id) == userMap.end()){
		User tmp(Id, list[UsrName]);
		fstream ufile(userFile);
		ufile.seekg(0);
		ufile.read(reinterpret_cast<char *> (&size), sizeof(size));
		size ++;
		ufile.seekp(0);
		ufile.write(reinterpret_cast<const char *> (& size), sizeof(size));
		ufile.seekp(User::SIZE * (size - 1));
		tmp.write(ufile);
		mp[Id] = size;
	}
	pos = userMap[MyInt(Id)];
	fstream ufile(userFile);
	User tmp;
	ufile.seekg((pos - 1) * User::SIZE + sizeof(size));
	tmp.read(ufile);
	tmp.editticket(list[Start], list[Target], list[TicketNum], list[TrainId], list[TicketClass], list[Date]);
	ufile.seekp((pos - 1) * User::SIZE + sizeof(size));
	tmp.write(ufile);
	Time now(list[Date]);
	modifyTicket(list[Start], list[Target], list[TrainId], now, list[TicketClass], list[TicketNum], trainMap);
}
