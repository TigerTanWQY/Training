#include <bits/stdc++.h>
using namespace std;

constexpr const int N = 5e4 + 3;
struct DSU {
	int fa[N * 3], rnk[N * 3];
	void init(int n)
	{ iota(fa, fa + n * 3 + 6, 0); }
	int fnd(int x)
	{ return fa[x] == x? x: fa[x] = fnd(fa[x]); }
	void mrge(int x, int y) {
		x = fnd(x); y = fnd(y);
		if(x == y) return;
		if(rnk[x] <= rnk[y]) {
			fa[x] = y;
			if(rnk[x] == rnk[y])
				++rnk[y];
		} else
			fa[y] = x;
	}
} c;

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int n, _q;
	cin >> n >> _q;
	c.init(n);
	int ans = 0;
	for(int op, x, y; _q--; ) {
		cin >> op >> x >> y;
		if(x > n || y > n)
		{ ++ans; continue; }
		if(op == 1) // Same
			if(c.fnd(x) == c.fnd(y + n) ||
				c.fnd(x + n) == c.fnd(y))
				{ ++ans; continue; }
			else {
				c.mrge(x, y);
				c.mrge(x + n, y + n);
				c.mrge(x + n * 2, y + n * 2);
			}
		else // Diff
			if(x == y ||
				c.fnd(x) == c.fnd(y) ||
				c.fnd(x) == c.fnd(y + n))
				{ ++ans; continue; }
			else {
				c.mrge(x + n, y);
				c.mrge(x + n * 2, y + n);
				c.mrge(x, y + n * 2);
			}
	}
	cout << ans << endl;
	return 0;
}
