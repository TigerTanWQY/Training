#include <bits/stdc++.h>
using namespace std;

constexpr const int N = 5e5 + 3;
struct DSU {
	int fa[N];
	void init()
	{ iota(fa, fa + N, 0); }
	int fnd(int x)
	{ return fa[x] != x? fa[x] = fnd(fa[x]): x; }
	void mrge(int u, int v) {
		u = fnd(u); v = fnd(v);
		if(u == v)
			return;
		fa[v] = u;
	}
} a;
vector<pair<int, int>> ask[N];
vector<int> G[N];
bitset<N> vis;
int ans[N];

void tarjan(int u) {
	vis[u] = true;
	for(const auto& v: G[u]) {
		if(vis[v])
			continue;
		tarjan(v);
		a.mrge(u, v);
	}
	for(const auto& [v, id]: ask[u])
		if(vis[v])
			ans[id] = a.fnd(v);
}

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	a.init();
	int n, _q, rt;
	cin >> n >> _q >> rt;
	for(int _ = n - 1, u, v; _--; ) {
		cin >> u >> v;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	for(int i = 1, u, v; i <= _q; ++i) {
		cin >> u >> v;
		if(u == v)
			ans[i] = u;
		else {
			ask[u].push_back({v, i});
			ask[v].push_back({u, i});
		}
	}
	tarjan(rt);
	for(int i = 1; i <= _q; ++i)
		cout << ans[i] << '\n';
	cout.flush(); return 0;
}
