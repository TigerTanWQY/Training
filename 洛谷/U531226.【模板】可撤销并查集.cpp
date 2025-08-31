#include <bits/stdc++.h>
using namespace std;

constexpr const int N = 5e5 + 8;
struct DSU {
	int fa[N], rnk[N];
	stack<tuple<bool, int, int>> stk;
	void init(int n) {
		iota(fa, fa + n + 3, 0);
		memset(rnk, 0, sizeof(int) * (n + 3));
	}
	int fnd(int x)
	{ return fa[x] == x? x: fnd(fa[x]); }
	void mrge(int x, int y) {
		x = fnd(x); y = fnd(y);
		if(x == y) return;
		if(rnk[x] <= rnk[y]) {
			stk.push({false, x, fa[x]});
			fa[x] = y;
			if(rnk[x] == rnk[y]) {
				stk.push({true, y, rnk[y]});
				++rnk[y];
			}
		} else {
			stk.push({false, y, fa[y]});
			fa[y] = x;
		}
	}
	void undo(void) {
		auto [tp, id, w] = stk.top(); stk.pop();
		if(tp) {
			rnk[id] = w;
			auto [_, id2, w2] = stk.top(); stk.pop();
			fa[id2] = w2;
		} else
			fa[id] = w;
	}
} c;

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int n, _q;
	cin >> n >> _q;
	c.init(n);
	for(int op, x, y; _q--; ) {
		cin >> op;
		if(op == 1) {
			cin >> x >> y;
			c.mrge(x, y);
		} else if(op == 2) {
			cin >> x >> y;
			cout << (c.fnd(x) == c.fnd(y)? "Yes": "No") << '\n';
		} else
			c.undo();
	}
	cout.flush(); return 0;
}
