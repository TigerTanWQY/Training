#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>
using namespace std;
using LL = long long;

const int N = 200003;
struct Edge {
	int u, v, w, idx;
	bool operator<(const Edge& x) const
	{ return w < x.w; }
} e[N];
vector<pair<int, int>> G[N];
int fa[N], d[N], f[22][N], g[22][N], n, m;
LL h[N];

void dfs(const int& u) {
	for(const auto& [v, w]: G[u])
		if(!d[v]) {
			d[v] = d[u] + 1;
			f[0][v] = u;
			g[0][v] = w;
			dfs(v);
		}
}

int fnd(const int& u) {
	if(fa[u] != u)
		fa[u] = fnd(fa[u]);
	return fa[u];
}

LL Kruskal() {
	sort(e + 1, e + m + 1);
	for(int i = 1; i <= n; ++i)
		fa[i] = i;
	LL res = 0;
	for(int i = 1; i <= m; ++i) {
		int u = fnd(e[i].u), v = fnd(e[i].v), w = e[i].w;
		if(u != v) {
			res += w;
			G[e[i].u].push_back({e[i].v, w});
			G[e[i].v].push_back({e[i].u, w});
			fa[u] = v;
		}
	}
	return res;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> m;
	for(int i = 1; i <= m; ++i) {
		cin >> e[i].u >> e[i].v >> e[i].w;
		e[i].idx = i;
	}
	LL res = Kruskal();
	d[1] = 1;
	dfs(1);
	for(int j = 1; j <= 19; ++j)
		for(int i = 1; i <= n; ++i) {
			f[j][i] = f[j - 1][f[j - 1][i]];
			g[j][i] = max(g[j - 1/*!!!*/][i], g[j - 1][f[j - 1][i]]);
		}
	for(int i = 1; i <= m; ++i) {
		int u = e[i].u, v = e[i].v;
		if(d[u] < d[v])
			swap(u, v);
		int ans = 0;
		for(int j = 0, x = d[u] - d[v]; x; ++j, x /= 2)
			if(x & 1) {
				ans = max(ans, g[j][u]);
				u = f[j][u];
			}
		if(u != v) {
			for(int j = 19; j >= 0; --j)
				if(f[j][u] != f[j][v]) {
					ans = max({ans, g[j][u], g[j][v]});
					u = f[j][u];
					v = f[j][v];
				}
			ans = max({ans, g[0][u], g[0][v]});
		}
		h[e[i].idx] = res - ans + e[i].w;
	}
	for(int i = 1; i <= m; ++i)
		cout << h[i] << '\n';
	cout.flush();
	return 0;
}