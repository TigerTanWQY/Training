#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
using namespace std;
using LL = long long;

constexpr const int N = 200003;
tuple<int, int, int, int> e[N];
vector<pair<int, int>> G[N];
int fa[N], d[N], f[22][N], g[22][N], n, m;
LL ans[N];

void dfs(const int u) {
	for(const auto& [v, w]: G[u])
		if(!d[v]) {
			d[v] = d[u] + 1;
			f[0][v] = u;
			g[0][v] = w;
			dfs(v);
		}
}

int fnd(const int x) {
	if(fa[x] != x)
		fa[x] = fnd(fa[x]);
	return fa[x];
}

LL Kruskal() {
	sort(e + 1, e + m + 1);
	for(int i = 0; i <= n; ++i)
		fa[i] = i;
	LL res = 0;
	for(int i = 1; i <= m; ++i) {
		auto [w, u, v, id] = e[i];
		u = fnd(u); v = fnd(v);
		if(u == v)
			continue;
		res += w;
		G[u].push_back({v, w});
		G[v].push_back({u, w});
		fa[v] = u;
	}
	return res;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n >> m;
	for(int i = 1, u, v, w; i <= m; ++i) {
		cin >> u >> v >> w;
		e[i] = {w, u, v, i};
	}
	LL res = Kruskal();
	d[1] = 1;
	dfs(1);
	for(int j = 1; j <= 19; ++j)
		for(int i = 1; i <= n; ++i) {
			f[j][i] = f[j - 1][f[j - 1][i]];
			g[j][i] = max(g[j - 1][i], g[j - 1][f[j - 1][i]]);
		}
	for(int i = 1; i <= m; ++i) {
		auto [w, u, v, id] = e[i];
		if(d[u] < d[v])
			swap(u, v);
		int tot = 0;
		for(int j = 0, x = d[u] - d[v]; x; ++j, x >>= 1)
			if(x & 1) {
				tot = max(tot, g[j][u]);
				u = f[j][u];
			}
		if(u != v) {
			for(int j = 19; j >= 0; --j)
				if(f[j][u] != f[j][v]) {
					tot = max({tot, g[j][u], g[j][v]});
					u = f[j][u];
					v = f[j][v];
				}
			tot = max({tot, g[0][u], g[0][v]});
		}
		ans[id] = res - tot + w;
	}
	for(int i = 1; i <= m; ++i)
		cout << ans[i] << '\n';
	cout.flush();
	return 0;
}