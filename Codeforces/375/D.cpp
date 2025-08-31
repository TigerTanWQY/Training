#include <bits/stdc++.h>
using namespace std;

constexpr const int N = 1e5 + 3;
vector<pair<int, int>> Q[N];
vector<int> G[N];
bool vis[N];
int sz[N], val[N], f[N], a[N], d[N], ans[N];

void dfs1(int u, int fa) {
	sz[u] = 1;
	for(const auto& v: G[u]) {
		if(v == fa)
			continue;
		dfs1(v, u);
		sz[u] += sz[v];
		if(f[u] == 0 || sz[f[u]] < sz[v])
			f[u] = v;
	}
}
void _dfs2(int u, int fa, int w) {
	if(w == -1)
		d[val[a[u]]] += w;
	val[a[u]] += w;
	if(w == 1)
		d[val[a[u]]] += w;
	for(const auto& v: G[u])
		if(v != fa && !vis[v])
			_dfs2(v, u, w);
}
void dfs2(int u, int fa, int flg) {
	for(const auto& v: G[u])
		if(v != fa && v != f[u])
			dfs2(v, u, 1);
	if(f[u]) {
		dfs2(f[u], u, 0);
		vis[f[u]] = true;
	}
	_dfs2(u, fa, 1);
	for(const auto& [x, id]: Q[u])
		ans[id] = d[x];
	if(f[u])
		vis[f[u]] = false;
	if(flg)
		_dfs2(u, fa, -1);
}

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	for(int i = 1; i <= n; ++i)
		cin >> a[i];
	for(int i = 1, u, v; i < n; ++i) {
		cin >> u >> v;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	for(int i = 1, u, k; i <= m; ++i) {
		cin >> u >> k;
		Q[u].push_back({k, i});
	}
	dfs1(1, 0);
	dfs2(1, 0, 1);
	for(int i = 1; i <= m; ++i)
		cout << ans[i] << '\n';
	cout.flush(); return 0;
}
