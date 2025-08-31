#include <iostream>
#include <cstring>
#include <utility>
#include <vector>
#include <algorithm>
using namespace std;

constexpr const int N = 303;
vector<pair<int, int>> G[N];
int f[N][N][3], g[N][3], n, m, k;

void dfs(const int u, const int fa) {
	f[u][0][0] = f[u][1][1] = 0;
	for(const auto& [v, w]: G[u]) {
		if(v == fa)
			continue;
		dfs(v, u);
		memcpy(g, f[u], sizeof(g));
		memset(f[u], 0x3f, sizeof(f[u]));
		for(int j = 0; j <= k; ++j)
			for(int t = 0; t <= j; ++t) {
				f[u][j][0] = min({f[u][j][0], f[v][t][0] + g[j - t][0] + (m == 2) * w, f[v][t][1] + g[j - t][0]});
				f[u][j][1] = min({f[u][j][1], f[v][t][1] + g[j - t][1] + w, f[v][t][0] + g[j - t][1]});
			}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n >> m >> k;
	for(int _ = 1, u, v, w; _ < n; ++_) {
		cin >> u >> v >> w;
		G[u].push_back({v, w});
		G[v].push_back({u, w});
	}
	if(n - k < m - 1) {
		cout << "-1";
		cout.flush();
		return 0;
	}
	memset(f, 0x3f, sizeof(f));
	dfs(1, 0);
	cout << f[1][k][1];
	cout.flush();
	return 0;
}