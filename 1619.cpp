#include <cstdio>
#include <iostream>
using namespace std;

const int N = 100010;
int to[N],pre[N], last[N], cnt;
int n, m, mx[N / 2], ad[N / 2], v[N], fa[N], st[N], ed[N], dfs_clock;

void add (int x, int y)
{
	to[++cnt] = y; pre[cnt] = last[x]; last[x] = cnt;
	to[++cnt] = x; pre[cnt] = last[y]; last[y] = cnt;
}


void dfs(int x)
{
	st[x] = ++dfs_clock;
	for (int i = last[x]; i; i = pre[i])
		if (to[i] != fa[x]) {
			fa[to[i]] = x;
			dfs(to[i]);
		}
	ed[x] = dfs_clock;
}
 
void Push_up(int o) {
	mx[o] = max(mx[(o * 2)], mx[(o * 2 + 1)]);
}
void Push_down(int o) {
	if (ad[o]) {
		mx[(o * 2)] += ad[o]; ad[(o * 2)] += ad[o];
		mx[(o * 2 + 1)] += ad[o]; ad[(o * 2 + 1)] += ad[o];
		ad[o] = 0;
	}
}
void update(int o, int l, int r, int ql, int qr, int v) {
	if (ql <= l && qr >= r) ad[o] += v, mx[o] += v;
	else {
		Push_down(o);
		if (ql <= ((l + r) / 2)) update((o * 2), l, ((l + r) / 2), ql, qr, v);
		if (qr >  ((l + r) / 2)) update((o * 2 + 1), ((l + r) / 2) + 1, r, ql, qr, v);
		Push_up(o);
	}
}
int query(int o, int l, int r, int ql, int qr) {
	if (ql <= l && qr >= r) return mx[o];
	else {
		int ans = -100000000;
		Push_down(o);
		if (ql <= ((l + r) / 2)) ans = max(ans, query((o  * 2), l, ((l + r) / 2), ql, qr));
		if (qr >  ((l + r) / 2)) ans = max(ans, query((o * 2+1), ((l + r) / 2) + 1, r, ql, qr));
		return ans;
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >>n >>m;
	for (long long  i = 1; i < n; ++i) {
		long long  x, y;
		cin >>x >>y;
		add(x, y);
	}
	for (long long  i = 1; i <= n; ++i) cin >>v[i];
	dfs(1);
	for (long long  i = 1; i <= n; ++i)
		update(1, 1, n, st[i], ed[i], v[i]);
	for (long long  i = 1; i <= m; ++i) {
		static long long  opt, x, y;
		cin >>opt >>x;
		if (opt) {
			cout <<query(1, 1, n, st[x], ed[x]) <<"\n";
		} else {
			cin >>y;
			update(1, 1, n, st[x], ed[x], -v[x] + y);
			v[x] = y;
		}
	}
	return 0;
}
