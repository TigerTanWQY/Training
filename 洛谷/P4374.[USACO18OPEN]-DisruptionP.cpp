#include <bits/stdc++.h>
using namespace std;

constexpr const int N = 5e4 + 3, LG = log2(N);
tuple<int, int, int> E[N];
vector<pair<int, int>> G[N];
int fa[LG+3][N], dep[N], bel[N], dsu[N], ans[N];

int fnd(int x)
{ return dsu[x] == x? x: dsu[x] = fnd(dsu[x]); }
void dfs(int u) {
	dep[u] = dep[fa[0][u]] + 1;
	for(const auto& [v, id]: G[u]) {
		if(v == fa[0][u])
			continue;
		fa[0][v] = u;
		bel[id] = v;
		dfs(v);
	}
}
int LCA(int u, int v) {
	if(dep[u] < dep[v])
		swap(u, v);
	for(int i = LG; ~i; --i)
		if(dep[fa[i][u]] >= dep[v])
			u = fa[i][u];
	if(u == v)
		return u;
	for(int i = LG; ~i; --i)
		if(fa[i][u] != fa[i][v]) {
			u = fa[i][u];
			v = fa[i][v];
		}
	return fa[0][u];
}

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	for(int i = 1, u, v; i < n; ++i) {
		cin >> u >> v;
		G[u].push_back({v, i});
		G[v].push_back({u, i});
	}
	for(int i = 1, u, v, w; i <= m; ++i) {
		cin >> u >> v >> w;
		E[i] = {w, u, v};
	}
	dep[0] = -1;
	dfs(1);
	for(int j = 1; j <= LG; ++j)
		for(int i = 1; i <= n; ++i)
			fa[j][i] = fa[j - 1][fa[j - 1][i]];
	iota(dsu + 1, dsu + n + 1, 1);
	memset(ans, -1, sizeof ans);
	sort(E + 1, E + m + 1);
	for(int i = 1; i <= m; ++i) {
		auto [w, u, v] = E[i];
		const int k = LCA(u, v);
		for(u = fnd(u); dep[u] > dep[k]; u = fnd(fa[0][u])) {
			ans[u] = w;
			dsu[u] = fa[0][u];
		}
		for(v = fnd(v); dep[v] > dep[k]; v = fnd(fa[0][v])) {
			ans[v] = w;
			dsu[v] = fa[0][v];
		}
	}
	for(int i = 1; i < n; ++i)
		cout << ans[bel[i]] << '\n';
	cout.flush(); return 0;
}
