#include <iostream>
#include <cstring>
using namespace std;
int num[8][100000];
int main() {
	char s[100000];
	cin.get(s, 100000);
	int len = strlen(s);
	char d[8];
	d[1] = 'A'; d[2] = 'B'; d[3] = 'C'; d[4] = 'D'; d[5] = 'E'; d[6] = 'F'; d[7] = 'G';
	/*for (int i = 0; i < len; i++) {
	if (s[i] == 'A') num[1]++;
	else if (s[i] == 'B') num[2]++;
	else if (s[i] == 'C') num[3]++;
	else if (s[i] == 'D') num[4]++;
	else if (s[i] == 'E') num[5]++;
	else if (s[i] == 'F') num[6]++;
	else if (s[i] == 'G') num[7]++;
	}*/
	int q;
	cin >> q;
	for (int i = 1; i <= q; i++) {
		int l, r;
		cin >> l >> r;
		int a[8] = { 0 };
		for (int j = l - 1; j < r; j++)
			if (s[j] == 'A') a[1]++;
			else if (s[j] == 'B') a[2]++;
			else if (s[j] == 'C') a[3]++;
			else if (s[j] == 'D') a[4]++;
			else if (s[j] == 'E') a[5]++;
			else if (s[j] == 'F') a[6]++;
			else if (s[j] == 'G') a[7]++;
			//for (int j = 1; j <= 7; j++)
			//	cout <<a[j] <<endl;
			if (((r - l) % 2 == 1) && (a[1] % 2 + a[3] % 2 + a[2] % 2 + a[4] % 2 + a[5] % 2 + a[6] % 2 + a[7] % 2) > 0)
				continue;
			if (((r - l) % 2 == 0) && (a[1] % 2 + a[3] % 2 + a[2] % 2 + a[4] % 2 + a[5] % 2 + a[6] % 2 + a[7] % 2) > 1)
				continue;
			int sum = l - 1; int k;
			for (int j = 1; j <= 7; j++) if (a[j] % 2 == 0) a[j] /= 2; else { a[j] = 0; k = j; }
			while (sum <= (l + r - 2) / 2) {
				if (a[1]) { s[sum] = 'A'; a[1]--; sum++; continue; }
				if (a[2]) { s[sum] = 'B'; a[2]--; sum++; continue; }
				if (a[3]) { s[sum] = 'C'; a[3]--; sum++; continue; }
				if (a[4]) { s[sum] = 'D'; a[4]--; sum++; continue; }
				if (a[5]) { s[sum] = 'E'; a[5]--; sum++; continue; }
				if (a[6]) { s[sum] = 'F'; a[6]--; sum++; continue; }
				if (a[7]) { s[sum] = 'G'; a[7]--; sum++; continue; }
				s[sum] = d[k];
				sum++;
			}
			for (int j = r - 1; j > (l + r - 2) / 2; j--)
				s[j] = s[l + r - 2 - j];
			//	cout <<s<<endl;
	}
	cout << s << endl;
	return 0;
}
//GFFGCBABCFFCDFDCF