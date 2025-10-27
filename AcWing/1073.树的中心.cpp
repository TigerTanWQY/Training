#include <bits/stdc++.h>
using namespace std;

constexpr const int N = 1e4 + 3;
vector<pair<int, int>> G[N];
int d1[N], d2[N], up[N], s1[N], s2[N];

void dfs1(int u, int fa) {
	for(const auto& [v, w]: G[u]) {
		if(v == fa) continue;
		dfs1(v, u);
		if(d1[v] + w >= d1[u]) {
			d2[u] = d1[u]; s2[u] = s1[u];
			d1[u] = d1[v] + w; s1[u] = v;
		} else if(d1[v] + w > d2[u])
		{ d2[u] = d1[v] + w; s2[u] = v; }
	}
}
void dfs2(int u, int fa) {
	for(const auto& [v, w]: G[u]) {
		if(v == fa)
			continue;
		if(s1[u] == v)
			up[v] = w + max(up[u], d2[u]);
		else
			up[v] = w + max(up[u], d1[u]);
		dfs2(v, u);
	}
}

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int n;
	cin >> n;
	for(int _ = 1, u, v, w; _ < n; ++_) {
		cin >> u >> v >> w;
		G[u].push_back({v, w});
		G[v].push_back({u, w});
	}
	dfs1(1, -1); dfs2(1, -1);
	int res = 1e9;
	for(int i = 1; i <= n; ++i)
		res = min(res, max(d1[i], up[i]));
	cout << res << endl;
	return 0;
}
