#include <cstdio>
#include <iostream>
using namespace std;
 
typedef long long LL;
const int N = 300010;
int n;
 
struct node{
	LL ac, w;
	bool operator < (const node& rhs) const {
		return ac > rhs.ac || (ac == rhs.ac && w > rhs.w);
	}
}a[N], hp[N], b[N];
 
template<typename T>
void mergesort(T *a, T *b, int l, int r) {
	if (l >= r) return;
	int mid = (l + r) >> 1;
	for (int i = l; i <= r; ++i) b[i] = a[i];
	mergesort(b, a, l, mid);
	mergesort(b, a, mid + 1, r);
	int i = l, j = mid + 1, k = l;
	while (i <= mid && j <= r) {
		if (b[j] < b[i]) a[k++] = b[j++];
		else a[k++] = b[i++];
	}
	while (i <= mid) a[k++] = b[i++];
	while (j <= r) a[k++] = b[j++];
}
 
bool cmp (const node &a, const node &b) {
	return a.w - a.ac > b.w - b.ac;
}
 
int cnt = 0;
void push(const node &v) {
	hp[++cnt] = v;
	for (int i = cnt; i > 1; i >>= 1) {
		if (cmp(hp[i >> 1], hp[i])) swap(hp[i >> 1], hp[i]);
		else break;
	}
}
void pop() {
	hp[1] = hp[cnt--];
	for (int i = 1, j; i < cnt; i = j) {
		if ((i << 1 | 1) <= cnt)
			j = cmp(hp[i << 1], hp[i << 1 | 1]) ? i << 1 | 1 : i << 1;
		else if ((i << 1) <= cnt) j = i << 1;
		else break;
		if (cmp(hp[i], hp[j])) swap(hp[i], hp[j]);
		else break;
	}
}
 
int main()
{
	cin >>n;
	long long ac, wg;
	scanf("%lld%lld", &ac, &wg);
	for (int i = 1; i < n; ++i) 
		scanf("%lld%lld", &a[i].ac, &a[i].w);
	n--;
	mergesort(a, b, 1, n);
//	sort(a + 1, a + n + 1);
	int now = 0, num = 0, ans = n + 1;
	for (now = 1; now <= n && a[now].ac > ac; ++now) push(a[now]);
	ans = now;
	do {
		if (!cnt) break;
		if (ac < hp[1].w - hp[1].ac + 1) break;
		ac -= hp[1].w - hp[1].ac + 1;
		pop();
		++num;
		while (ac < a[now].ac && now <= n) {
			push(a[now]);
			++now;
		}
		ans = min(ans, now - num);
	} while (now <= n || cnt);
	printf("%d\n", ans);
	return 0;
}
