class Train() {
	friend User;
	friend Admistration;
private:
	string Name; //������ 
	static int total; //�ܳ����� 
	int id; //����ID 
	int Number; //վ̨�� 
	list<string> ZhanTai; //վ̨�� 
	list<double> Price[40][10]; //�۸� 
	list<int> Remain[40][10]; //��Ʊ 
	list<Time> Arrival; //����ʱ�� 
	list<Time> Dapart; //����ʱ�� 
	list<int> Kilometer; //����� 
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
