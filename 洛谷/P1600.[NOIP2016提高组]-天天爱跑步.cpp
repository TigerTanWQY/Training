#include <bits/stdc++.h>
#define pb push_back
#define pii pair <int, int>
#define mkpr make_pair
#define fi first
#define se second
using namespace std;
const int N = 3e5 + 5, D = 3e5;
int n, m, w[N], d[N], f[N][25], c[2][N<<1], ans[N], dep[N];
vector <int> g[N];
vector <pii> add[N], del[N];
struct path {int u, v;} p[N];
void Dfs(int u, int p) {
	f[u][0] = p;
	dep[u] = dep[p] + 1;
	for (int v : g[u]) {
		if (v == p) continue ;
		Dfs(v, u);
	}
}
void InitLCA() {
	for (int j = 1; j <= 21; j++) {
		for (int i = 1; i <= n; i++) {
			f[i][j] = f[f[i][j-1]][j-1];
		}
	}
}
int LCA(int u, int v) {
	if (dep[u] < dep[v]) swap(u, v);
	for (int i = 21; i >= 0; i--) if (dep[f[u][i]] >= dep[v]) u = f[u][i];
	if (u == v) return u;
	for (int i = 21; i >= 0; i--) if (f[u][i] != f[v][i]) u = f[u][i], v = f[v][i];
	return f[u][0];
}
void Dfs2(int u) {
	int pre1 = c[0][w[u]+dep[u]+D], pre2 = c[1][w[u]-dep[u]+D];
	for (pii cur : add[u]) ++c[cur.fi][cur.se+D];
	for (pii cur : del[u]) --c[cur.fi][cur.se+D];
	for (int v : g[u]) {
		if (v == f[u][0]) continue ;
		Dfs2(v);
	}
	ans[u] = c[0][w[u]+dep[u]+D] - pre1 + c[1][w[u]-dep[u]+D] - pre2;
}
void Solve() {
	cin >> n >> m;
	for (int i = 1; i < n; i++) {
		int u, v; cin >> u >> v;
		g[u].pb(v), g[v].pb(u);
	}
	for (int i = 1; i <= n; i++) cin >> w[i];
	Dfs(1, 0); InitLCA();
	for (int i = 1; i <= m; i++) {
		int u, v; cin >> u >> v;
		int lc = LCA(u, v);
		add[u].pb(mkpr(0, dep[u])), del[f[lc][0]].pb(mkpr(0, dep[u]));
		add[v].pb(mkpr(1, dep[u]-2*dep[lc])), del[lc].pb(mkpr(1, dep[u]-2*dep[lc]));
	}
	Dfs2(1);
	for (int i = 1; i <= n; i++) cout << ans[i] << ' ';
}
int main() {
	cin.tie(nullptr)->sync_with_stdio(0);
	Solve();
	cout.flush(); return 0;
}
