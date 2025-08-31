#include <bits/stdc++.h>
using namespace std;

constexpr const int N = 1e4 + 3;
vector<pair<int, int>> G[N];
int fa[17][N], dep[N], dis[N];

void dfs(const int u) {
	dep[u] = dep[fa[0][u]] + 1;
	for(const auto& [v, w]: G[u]) {
		if(v == fa[0][u])
			continue;
		fa[0][v] = u;
		dis[v] = dis[u] + w;
		dfs(v);
	}
}

int LCA(int u, int v) {
	if(dep[u] < dep[v])
		swap(u, v);
	for(int j = 14; j >= 0; --j)
		if(dep[fa[j][u]] >= dep[v])
			u = fa[j][u];
	if(u == v)
		return u;
	for(int j = 14; j >= 0; --j)
		if(fa[j][u] != fa[j][v]) {
			u = fa[j][u];
			v = fa[j][v];
		}
	return fa[0][u];
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, q;
	cin >> n >> q;
	for(int _ = 1, u, v, w; _ < n; ++_) {
		cin >> u >> v >> w;
		G[u].push_back({v, w});
		G[v].push_back({u, w});
	}
	dfs(1);
	for(int j = 1; j <= 14; ++j)
		for(int i = 1; i <= n; ++i)
			fa[j][i] = fa[j - 1][fa[j - 1][i]];
	for(int u, v; q--; cout.put('\n')) {
		cin >> u >> v;
		cout << dis[u] + dis[v] - 2 * dis[LCA(u, v)];
	}
	cout.flush();
	return 0;
}
