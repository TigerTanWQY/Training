#include <bits/stdc++.h>
using namespace std;
using ULL = unsigned long long;

constexpr const int N = 13;
bitset<N> vis;
ULL G[N][N], ans = 1ULL << 60;
int n;

void dfs(int u, ULL tot) {
	if(u == n) {
		ans = min(ans, tot);
		return;
	}
	vis[u] = true;
	for(int v = 1; v <= n; ++v)
		if(~G[u][v] && !vis[v])
			dfs(v, tot ^ G[u][v]);
	vis[u] = false;
}

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int m;
	cin >> n >> m;
	for(int i = 1; i <= n; ++i) {
		for(int j = 1; j <= n; ++j)
			G[i][j] = -1;
		G[i][i] = 0;
	}
	for(int _ = m, u, v; _--; ) {
		ULL w;
		cin >> u >> v >> w;
		G[u][v] = G[v][u] = w;
	}
	dfs(1, 0);
	cout << ans << endl;
	return 0;
}
