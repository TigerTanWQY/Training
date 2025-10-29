#include <bits/stdc++.h>
using namespace std;

constexpr const int N = 1503;
vector<int> G[N];
bool st[N];
int f[N][3];

void dfs(int u) {
	f[u][0] = 0; f[u][1] = 1e9;
	for(const auto& v: G[u]) {
		dfs(v);
		f[u][0] += min(f[v][1], f[v][2]);
		f[u][2] += min({f[v][0], f[v][1], f[v][2]});
	}
	for(const auto& v: G[u])
		f[u][1] = min(f[u][1], f[u][0] + f[v][2] - min(f[v][1], f[v][2]));
}

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int n;
	cin >> n;
	for(int i = 1, u, m; i <= n; ++i) {
		cin >> u >> f[u][2] >> m;
		for(int v; m--; ) {
			cin >> v;
			G[u].push_back(v);
			st[v] = true;
		}
	}
	int rt = 1;
	for(; st[rt]; ++rt);
	dfs(rt);
	cout << min(f[rt][1], f[rt][2]) << endl;
	return 0;
}
