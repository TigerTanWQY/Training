#include <bits/stdc++.h>
using namespace std;

constexpr const int N = 203;
bool vis[N<<4];
int fa[N<<5], x[N<<4], y[N<<4], id[N], m;

int fnd(int p)
{ return fa[p] == p? p: fa[p] = fnd(fa[p]); }

bool cross(int x1, int x2, int y1, int y2) {
	if(x1 == x2 || y1 == y2 || x1 == y2 || x2 == y1)
		return 0;
	else if(x1 < x2 && y1 < y2 && x2 < y1)
		return 1;
	else if(x2 < x1 && y2 < y1 && x1 < y2)
		return 1;
	else
		return 0;
}

bool chk() {
	for(int i = 1; i <= m<<1; ++i)
		fa[i] = i;
	for(int i = 1; i <= m; ++i) {
		if(vis[i])
			continue;
		for(int j = 1; j <= m; ++j) {
			if(vis[j])
				continue;
			if(!cross(x[i], x[j], y[i], y[j]))
				continue;
			int fi = fnd(i), fj = fnd(j);
			if(fi == fj)
				return false;
			fa[fi] = fnd(j+m); fa[fj] = fnd(i+m);
		}
	}
	return true;
}

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int _T;
	cin >> _T;
	for(int n; _T--; cout.put('\n')) {
		cin >> n >> m;
		for(int i = 1; i <= m; ++i)
			cin >> x[i] >> y[i];
		for(int i = 1, p; i <= n; ++i) {
			cin >> p;
			id[p] = i;
		}
		if(m > 3 * n + 6) {
			cout << "NO";
			continue;
		}
		for(int i = 1; i <= m; ++i) {
			int a = id[x[i]], b = id[y[i]];
			x[i] = min(a, b),
			y[i] = max(a, b);
		}
		for(int i = 1; i <= m; ++i)
			if(y[i] == x[i] + 1 || (y[i] == n && x[i] == 0))
				vis[i] = true;
		cout << (chk()? "YES": "NO");
		for(int i = 1; i <= n; ++i)
			vis[i] = false;
	}
	cout.flush(); return 0;
}
