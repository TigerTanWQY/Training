#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int N = 100003;
vector<int> G[N];
int d[N], f[20][N], g[20][N];

void dfs(const int& u) {
	for(const auto& v: G[u])
		if(!d[v]) {
			d[v] = d[u] + 1;
			f[0][v] = u;
			dfs(v);
		}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n, q;
	cin >> n >> q;
	for(int i = 1, x; i <= n; ++i) {
		cin >> x;
		g[0][i] = x;
		for(int j = 1; j <= 17; ++j)
			g[j][i] = 0x3f3f3f3f;
	}
	for(int _ = 1, u, v; _ < n; ++_) {
		cin >> u >> v;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	d[1] = 1;
	dfs(1);
	for(int j = 1; j <= 17; ++j)
		for(int i = 1; i <= n; ++i) {
			f[j][i] = f[j - 1][f[j - 1][i]];
			g[j][i] = min(g[j - 1][i], g[j - 1][f[j - 1][i]]);
		}
	for(int u, v; q--; ) {
		cin >> u >> v;
		if(d[u] < d[v])
			swap(u, v);
		int ans = 0x3f3f3f3f;
		for(int j = 0, x = d[u] - d[v]; x; x /= 2, ++j)
			if(x & 1) {
				ans = min(ans, g[j][u]);
				u = f[j][u];
			}
		if(u != v) {
			for(int j = 17; j >= 0; --j)
				if(f[j][u] != f[j][v]) {
					ans = min({ans, g[j][u], g[j][v]});
					u = f[j][u];
					v = f[j][v];
				}
			ans = min({ans, g[0][u], g[0][v]});
			u = f[0][u];
		}
		ans = min(ans, g[0][u]);
		cout << ans << '\n';
	}
	cout.flush();
	return 0;
}