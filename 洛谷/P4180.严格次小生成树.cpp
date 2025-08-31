#include <bits/stdc++.h>
using namespace std;
using LL = long long;

constexpr const int N = 1e5 + 3;
vector<tuple<LL, int, int>> e;
vector<pair<int, LL>> G[N];
bitset<N * 6> idx;
int dsu[N], fa[20][N], dep[N], n;
LL st[2][20][N];

int fnd(const int x) {
	if(dsu[x] != x)
		dsu[x] = fnd(dsu[x]);
	return dsu[x];
}

LL Kruskal() {
	sort(e.begin(), e.end());
	for(int i = 0; i <= n; ++i)
		dsu[i] = i;
	LL res = 0;
	for(int i = 0; i < e.size(); ++i) {
		auto [w, u, v] = e[i];
		int fu = fnd(u), fv = fnd(v);
		if(fu == fv)
			continue;
		dsu[fv] = fu;
		res += w;
		G[u].push_back({v, w});
		G[v].push_back({u, w});
		idx[i] = true;
	}
	return res;
}

void dfs(const int u, const int fu) {
	for(const auto& [v, w]: G[u]) {
		if(v == fu)
			continue;
		dep[v] = dep[u] + 1;
		fa[0][v] = u;
		st[0][0][v] = w;
		st[1][0][v] = -0x3f3f3f3f3f3f3f3f;
		dfs(v, u);
	}
}

int LCA(int u, int v) {
	if(dep[u] < dep[v])
		swap(u, v);
	for(int i = 17; i >= 0; --i)
		if(dep[fa[i][u]] >= dep[v])
			u = fa[i][u];
	if(u == v)
		return u;
	for(int i = 17; i >= 0; --i)
		if(fa[i][u] != fa[i][v]) {
			u = fa[i][u];
			v = fa[i][v];
		}
	return fa[0][u];
}

LL get(int u, const int v, const LL t) {
	LL res = -0x3f3f3f3f3f3f3f3f;
	for(int i = 17; i >= 0; --i)
		if(dep[fa[i][u]] >= dep[v]) {
			if(t != st[0][i][u])
				res = max(res, st[0][i][u]);
            else
				res = max(res, st[1][i][u]);
            u = fa[i][u];
		}
	return res;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int m;
	cin >> n >> m;
	for(int u, v; m--; ) {
		LL w;
		cin >> u >> v >> w;
		e.push_back({w, u, v});
		e.push_back({w, v, u});
	}
	LL tot = Kruskal();
	dep[1] = 1;
	dfs(1, 0);
	for(int j = 1; j <= 17; ++j)
		for(int i = 1; i <= n; ++i) {
			fa[j][i] = fa[j - 1][fa[j - 1][i]];
			st[0][j][i] = max(st[0][j - 1][i], st[0][j - 1][fa[j - 1][i]]);
			st[1][j][i] = max(st[1][j - 1][i], st[1][j - 1][fa[j - 1][i]]);
			if(st[0][j - 1][i] > st[0][j - 1][fa[j - 1][i]])
				st[1][j][i] = max(st[1][j][i], st[0][j - 1][fa[j - 1][i]]);
            else if(st[0][j - 1][i] < st[0][j - 1][fa[j - 1][i]])
				st[1][j][i] = max(st[1][j][i], st[0][j - 1][i]);
		}
	LL ans = 0x3f3f3f3f3f3f3f3f;
	for(int i = 0; i < e.size(); ++i)
		if(!idx[i]) {
			auto [w, u, v] = e[i];
			int cf = LCA(u, v);
			LL res = max(get(u, cf, w), get(v, cf, w));
			ans = min(ans, w - res);
		}
	cout << ans + tot << endl;
	return 0;
}
