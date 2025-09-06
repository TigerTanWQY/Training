#include <bits/stdc++.h>
using namespace std;

constexpr const int N = 2e5 + 3;
bool col[N];
int fa[N], rnk[N], cnt[N];

int fnd(int x)
{ return fa[x] == x? x: fa[x] = fnd(fa[x]); }

void mrge(int u, int v) {
	u = fnd(u); v = fnd(v);
	if(u == v)
		return;
	if(rnk[u] < rnk[v]) {
		fa[u] = v;
		cnt[v] += cnt[u];
	} else if (rnk[u] > rnk[v]) {
		fa[v] = u;
		cnt[u] += cnt[v];
	} else {
		fa[v] = u;
		cnt[u] += cnt[v];
		++rnk[u];
	}
}

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int n, _q;
	cin >> n >> _q;
	iota(fa + 1, fa + n + 1, 1);
	for(int op, u, v; _q--; ) {
		cin >> op;
		if(op == 1) {
			cin >> u >> v;
			mrge(u, v);
		} else if (op == 2) {
			cin >> v;
			if(!col[v]) {
				col[v] = true;
				++cnt[fnd(v)];
			} else {
				col[v] = false;
				--cnt[fnd(v)];
			}
		} else {
			cin >> v;
			cout << (cnt[fnd(v)] > 0? "Yes": "No") << '\n';
		}
	}
	cout.flush(); return 0;
}
