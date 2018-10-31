
/**
  * add the train in the file and O(n^2) add the train on the tree.
*/
void insertTrain(const Train &train, logclass &log){
	list<string>::iterator i, j;
	for (i = nod.ZhanTai.begin(); i != nod.ZhanTai.end(); i++)
		for (j = i, j++; j != nod.ZhanTai.end(); j++)
			TrainMap.insert(QueryInformation(*i, *j, nod.Name));
}

/**
  * find the train in the file and O(n^2) delete the train on the tree.

*/
bool delTrain(const Train &train, logclass &log){
	
}

/**
  * O(n) modify, no changes on the tree.
*/
bool changeTrain(const string &trainid, logclass &log){

}

User seeUser(int userid,const UMAP &usermap,char* inFile){
	int k = usermap[userid];
	fstream fio(inFile);
	fio.seekg(User::Size*(k-1)+sizeof(size_t),ios::beg);
	User a;
	a.read(fio);
	return a;
}
void onSold(const string &trainid, const string &date) {
	
}




void true_register(string s1,string s2,UMAP &usermap){
	size_t n;
	fstream fio(Userfile);
	fio.read(reinterpret_cast<char *>(&n),sizeof(size_t));
	++n;
	User x((int)n, s1, s2);
	registe(x, usermap);
}

void registe(User &x, UMAP &usermap){
	int n=x.registe(Userfile);
	UserInformation j = UserInformation(x.getID());
	pair<UserInformation, int> userp(j, n);
	usermap.insert(userp);
}


/**
  * find the id on the tree, read the information in the file, print the information in some format.
*/
void seeUser(int userid){
}

/**
  * design a format to print the log and save the information in log.txt
*/
void checkLog() {
	
}
