#include <bits/stdc++.h>
using namespace std;

constexpr const int N = 2e3 + 3;
vector<int> G[N], Gr[N];
bitset<N> vis, visr;
int k[N], f[N][N], cnt[N];

int dfs(int u) {
	if(vis[u])
		return k[u];
	vis[u] = true;
	for(const auto& v: G[u])
		k[u] = min(k[u], dfs(v) - 1);
	f[k[u]][++cnt[k[u]]] = u;
	return k[u];
}

void dfsr(int u) {
	visr[u] = true;
	for(const auto& v: Gr[u])
		if(!visr[v])
			dfsr(v);
}

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	for(int i = 1; i <= n; ++i)
		cin >> k[i];
	for(int u, v; m--; ) {
		cin >> u >> v;
		G[u].push_back(v);
		Gr[v].push_back(u);
	}
	for(int i = 1; i <= n; ++i)
		dfs(i);
	for(int i = 1; i <= n; ++i)
		for(int j = 1; j <= cnt[i]; ++j)
			cout << f[i][j] << ' ';
	cout.put('\n');
	for(int i = 1; i <= n; ++i) {
		visr.reset();
		dfsr(i);
		int u = n;
		for(int j = n; j; --j) {
			if(u > j)
				break;
			for(int t = 1; t <= cnt[j]; ++t)
				if(!visr[f[j][t]])
					--u;
		}
		cout << u << ' ';
	}
	cout << endl; return 0;
}
