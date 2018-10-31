#include <cstdio>
#include <iostream>
using namespace std;
 
const int INF = 1e9;
const int N = 100010;
int n, m, mx[100010], ad[100010], v[100010], fa[100010], st[100010], ed[100010], dfs_clock;

int to[100010], pre[100010], last[100010], cnt;
 
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
	mx[o] = max(mx[o << 1], mx[o << 1 | 1]);
}
void Push_down(int o) {
	if (ad[o]) {
		mx[o << 1] += ad[o]; ad[o << 1] += ad[o];
		mx[o << 1 | 1] += ad[o]; ad[o << 1 | 1] += ad[o];
		ad[o] = 0;
	}
}

void update(int o, int l, int r, int ql, int qr, int v) {
	if (ql <= l && qr >= r) ad[o] += v, mx[o] += v;
	else {
		Push_down(o);
		if (ql <= (l + r) >> 1) update(o << 1, l, (l + r) >> 1, ql, qr, v);
		if (qr >  (l + r) >> 1) update(o << 1 | 1, (l + r) >> 1 + 1, r, ql, qr, v);
		Push_up(o);
	}
}

int query(int o, int l, int r, int ql, int qr) {
	if (ql <= l && qr >= r) return mx[o];
	else {
		int ans = -INF;
		Push_down(o);
		if (ql <= (l + r) >> 1) ans = max(ans, query(o << 1, l, (l + r) >> 1, ql, qr));
		if (qr >  (l + r) >> 1) ans = max(ans, query(o << 1 | 1, (l + r) >> 1 + 1, r, ql, qr));
		return ans;
	}
}
 
int main()
{
	cin >>n >>m;
	for (int i = 1; i < n; ++i) {
		int x, y;
		cin >>x >>y;
		add(x, y);
	}
	for (int i = 1; i <= n; ++i) cin >>v[i];
	dfs(1);
	for (int i = 1; i <= n; ++i)
		update(1, 1, n, st[i], ed[i], v[i]);
	for (int i = 1; i <= m; ++i) {
		static int opt, x, y;
		cin >>opt >>x;
		if (opt) {
			cout <<query(1, 1, n, st[x], ed[x])<<endl;
		} else {
			cin >>y;
			update(1, 1, n, st[x], ed[x], -v[x] + y);
			v[x] = y;
		}
	}
	return 0;
}
