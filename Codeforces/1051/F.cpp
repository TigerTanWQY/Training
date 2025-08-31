#include <bits/stdc++.h>
using namespace std;

constexpr const int N = 1e5 + 3;
vector<tuple<int, int, int>> e;
vector<pair<int, int>> G[N];
int fa[20][N], dep[N], dsu[N], sz[N], n;

int fnd(const int x) {
	if(dsu[x] != x)
		dsu[x] = fnd(dsu[x]);
	return dsu[x];
}
/*
所有简单稀疏无向图的最短路可以用生成树+LCA做吗？

rt。[这道题](https://www.luogu.com.cn/problem/CF1051F) 可以这么做，但这种做法具有普遍性吗？

另外如果第一问成立，那么这种做法可以推广到一般图吗？
*/
void Kruskal() {
	sort(e.begin(), e.end());
	for(int i = 0; i <= n; ++i)
		dsu[i] = i;
	for(auto [w, u, v]: e) {
		u = fnd(u); v = fnd(v);
		if(u == v)
			continue;
		dsu[v] = u;
		G[u].push_back({v, w});
		G[v].push_back({u, w});
	}
}

void getd(const int u) {
	dep[u] = dep[fa[0][u]] + 1;
	for(const auto& [v, _]: G[u])
		if(v != fa[0][u]) {
			fa[0][v] = u;
			getd(v);
		}
}

int LCA(int u, int v) {
	if(dep[u] < dep[v])
		swap(u, v);
	for(int j = 17; j >= 0; --j)
		if(dep[fa[j][u]] > dep[v])
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

int dis(int u, int v) {
	u = fnd(u); v = fnd(v);
	if(u == v)
		return 0;
	return sz[u] + sz[v];
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int m, q;
	cin >> n >> m;
	for(int u, v, w; m--; ) {
		cin >> u >> v >> w;
		e.push_back({w, u, v});
		e.push_back({w, v, u});
	}
	Kruskal();
	for(int i = 0; i <= n; ++i) {
		dsu[i] = i;
		sz[i] = 0;
	}
	getd(1);
	for(int j = 1; j <= 17; ++j)
		for(int i = 1; i <= n; ++i)
			fa[j][i] = fa[j - 1][fa[j - 1][i]];
	cin >> q;
	for(int u, v; q--; cout.put('\n')) {
		cin >> u >> v;
		cout << dis(u, v);
	}
	cout.flush();
	return 0;
}
