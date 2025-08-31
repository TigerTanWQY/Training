#include <bits/stdc++.h>
using namespace std;

constexpr const int N = 1e5 + 3;
vector<int> G[N];
int fa[20][N], d[N];

void dfs(const int u) {
	for(const auto& v: G[u]) {
		if(v == fa[0][u])
			continue;
		d[v] = d[u] + 1;
		fa[0][v] = u;
		dfs(v);
	}
}

int LCA(int u, int v) {
	if(d[u] < d[v])
		swap(u, v);
	for(int j = 17; j >= 0; --j)
		if(d[fa[j][u]] >= d[v])
			u = fa[j][u];
	if(u == v)
		return u;
	for(int j = 17; j >= 0; --j)
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
	cin >> n;
	for(int _ = 1, u, v; _ < n; ++_) {
		cin >> u >> v;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	dfs(1);
	for(int j = 1; j <= 17; ++j)
		for(int i = 1; i <= n; ++i)
			fa[j][i] = fa[j - 1][fa[j - 1][i]];
	cin >> q;
	for(int u, v; q--; cout.put('\n')) {
		cin >> u >> v;
		cout << d[u] + d[v] - 2 * d[LCA(u, v)];
	}
	cout.flush();
	return 0;
}
