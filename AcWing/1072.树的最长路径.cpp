#include <bits/stdc++.h>
using namespace std;

constexpr const int N = 10003;
vector<pair<int, int>> G[N];
int f[2][N], ans = 0;

void dfs(int u, int fa) {
	for(const auto& [v, w]: G[u]) {
		if(v == fa)
			continue;
		dfs(v, u);
		if(f[0][v] + w > f[0][u])
			f[1][u] = f[0][u], f[0][u] = f[0][v] + w;
		else if(f[0][v] + w > f[1][u])
			f[1][u] = f[0][v] + w;
	}
	ans = max(ans, f[0][u] + f[1][u]);
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
	dfs(1, -1);
	cout << ans << endl;
	return 0;
}
