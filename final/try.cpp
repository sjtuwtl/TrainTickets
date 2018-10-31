#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
#include "linkList.hpp"
int main() {
	list<int> lis;
	list<int>::iterator it;
	for (int i = 0; i < 100; ++i) {
		lis.insert(0, i);
	}
	for (it = lis.begin(); it != lis.end(); ++it) {
		cout << *it << endl;
	}
}