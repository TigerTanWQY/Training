#include <bits/stdc++.h>
using namespace std;

constexpr const int N = 1e5 + 3;
vector<int> G[N];
int dfn[N], low[N], sz[N], idx = 0, n;
long long ans[N];

void tarjan(int u) {
	dfn[u] = low[u] = ++idx;
	long long tot = 0;
	sz[u] = 1;
	for(const auto& v: G[u])
		if(!dfn[v]) {
			tarjan(v);
			sz[u] += sz[v];
			if(low[v] >= dfn[u]) {
				ans[u] += sz[v] * tot;
				tot += sz[v];
			}
			low[u] = min(low[u], low[v]);
		} else
			low[u] = min(low[u], dfn[v]);
	ans[u] += (n - tot - 1) * tot + n - 1;
}

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int m;
	cin >> n >> m;
	for(int u, v; m--; ) {
		cin >> u >> v;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	tarjan(1);
	for(int i = 1; i <= n; ++i)
		cout << (ans[i] * 2) << '\n';
	cout.flush(); return 0;
}
