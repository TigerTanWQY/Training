#include <bits/stdc++.h>
using namespace std;

constexpr const int N = 1e5 + 3;
vector<vector<int>> scc;
vector<int> G[N];
stack<int> stk;
bool ins[N], vis[N];
int dfn[N], low[N], bel[N], f[N], way[N], idx = 0;

void dfs(int u) {
	low[u] = dfn[u] = ++idx;
	stk.push(u);
	ins[u] = true;
	for(const auto& v: G[u])
		if(!dfn[v]) {
			dfs(v);
			low[u] = min(low[u], low[v]);
		} else if(ins[v])
			low[u] = min(low[u], dfn[v]);
	if(dfn[u] == low[u]) {
		scc.push_back({});
		while(!stk.empty()) {
			int v = stk.top();
			stk.pop();
			ins[v] = false;
			scc.back().push_back(v);
			bel[v] = scc.size()-1;
			if(v == u)
				break;
		}
	}
}

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int n, m, p;
	cin >> n >> m >> p;
	for(int u, v; m--; ) {
		cin >> u >> v;
		G[u].push_back(v);
	}
	scc.push_back({});
	for(int i = 1; i <= n; ++i)
		if(!dfn[i])
			dfs(i);
	int ans = 0, w = 0;
	for(int i = 1; i < scc.size(); ++i) {
		way[i] = 1; f[i] = 0;
		for(const auto& u: scc[i])
			for(const auto& v: G[u])
				if(!vis[bel[v]] && bel[v] != i) {
					vis[bel[v]] = true;
					if(f[bel[v]] > f[i]) {
						f[i] = f[bel[v]];
						way[i] = 0;
					}
					if(f[bel[v]] == f[i])
						way[i] = (way[i] + way[bel[v]]) % p;
				}
		f[i] += scc[i].size();
		if(f[i] > ans) {
			ans = f[i];
			w = 0;
		}
		if(f[i] == ans)
			w = (w + way[i]) % p;
		for(const auto& u: scc[i])
			for(const auto& v: G[u])
				if(vis[bel[v]])
					vis[bel[v]] = false;
	}
	cout << ans << '\n' << w << endl;
	return 0;
}
