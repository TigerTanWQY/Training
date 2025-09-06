#include <bits/stdc++.h>
using namespace std;

constexpr const int N = 2e5 + 3;
int fa[N], cnt[N];

int fnd(int x)
{ return fa[x] == x? x: fa[x] = fnd(fa[x]); }

void mrge(int x, int y) {
	x = fnd(x); y = fnd(y);
	if(x == y)
		return;
	fa[y] = x;
}

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	iota(fa, fa + n + 1, 0);
	for(int u, v; m--; ) {
		cin >> u >> v;
		mrge(u, v);
		++cnt[u]; ++cnt[v];
	}
	for(int i = 1; i <= n; ++i)
		if(fnd(i) != fnd(1) || cnt[i] != 2) {
			cout << "No" << endl;
			return 0;
		}
	cout << "Yes" << endl;
	return 0;
}
