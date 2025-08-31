#include <bits/stdc++.h>
using namespace std;

constexpr const int N = 5e5 + 3;
vector<int> G[N];
int fa[22][N], dep[N];

void dfs(int u) {
	dep[u] = dep[fa[0][u]] + 1;
	for(const auto& v: G[u])
		if(v != fa[0][u])
		{ fa[0][v] = u; dfs(v); }
}

int LCA(int u, int v) {
	if(dep[u] < dep[v])
		swap(u, v);
	for(int j = 19; ~j; --j)
		if(dep[fa[j][u]] >= dep[v])
			u = fa[j][u];
	if(u == v)
		return u;
	for(int j = 19; ~j; --j)
		if(fa[j][u] != fa[j][v])
		{ u = fa[j][u]; v = fa[j][v]; }
	return fa[0][u];
}

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int n, _q, rt;
	cin >> n >> _q >> rt;
	for(int _ = n - 1, u, v; _--; ) {
		cin >> u >> v;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	dfs(rt);
	for(int j = 1; j <= 19; ++j)
		for(int i = 1; i <= n; ++i)
			fa[j][i] = fa[j - 1][fa[j - 1][i]];
	for(int u, v; _q--; cout.put('\n')) {
		cin >> u >> v;
		cout << LCA(u, v);
	}
	cout.flush(); return 0;
}
