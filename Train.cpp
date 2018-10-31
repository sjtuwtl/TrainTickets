class Train() {
	friend User;
	friend Admistration;
private:
	string Name; //车次名 
	static int total; //总车次数 
	int id; //车次ID 
	int Number; //站台数 
	list<string> ZhanTai; //站台名 
	list<double> Price[40][10]; //价格 
	list<int> Remain[40][10]; //余票 
	list<Time> Arrival; //到达时间 
	list<Time> Dapart; //发车时间 
	list<int> Kilometer; //里程数 
	map<QueryInformation, int> mp;
public:
	
	Train(): {
		
		//chushihua
	}
	~Train(): {
	
	}

	int DuringKilometer(string x, string y){
		
	}
	Time DuringTime(string x, string y) {
		
	}
	protected:
	
}
