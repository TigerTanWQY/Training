#include <iostream>
#include <vector>
#include <bitset>
#include <stack>
#include <array>
#include <algorithm>
using namespace std;

constexpr const int N = 100'003;
array<vector<int>, N> G, scc;
stack<int> stk;
bitset<N> ins;
array<int, N> dfn, low, bel;
int idx = 0, cnt = 0;

void dfs(const int& u) {
	dfn[u] = low[u] = ++idx;
	stk.push(u);
	ins[u] = true;
	for(const auto& v: G[u])
		if(!dfn[v]) {
			dfs(v);
			low[u] = min(low[u], low[v]);
		} else if(ins[v])
			low[u] = min(low[u], dfn[v]);
	if(dfn[u] == low[u]) {
		++cnt;
		while(!stk.empty()) {
			int v = stk.top();
			stk.pop();
			ins[v] = false;
			scc[cnt].push_back(v);
			bel[v] = cnt;
			if(v == u)
				break;
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, m, P;
	cin >> n >> m >> P;
	for(int u, v; m--; ) {
		cin >> u >> v;
		G[u].push_back(v);
	}
	for(int u = 1; u <= n; ++u)
		if(!dfn[u])
			dfs(u);
	bitset<N> vis;
	array<int, N> f, way;
	int ans = 0, w = 0;
	for(int i = 1; i <= cnt; ++i) {
		way[i] = 1;
		f[i] = 0;
		for(const auto& u: scc[i])
			for(const auto& v: G[u])
				if(!vis[bel[v]] && bel[v] != i) {
					vis[bel[v]] = true;
					if(f[bel[v]] > f[i]) {
						f[i] = f[bel[v]];
						way[i] = 0;
					}
					if(f[bel[v]] == f[i])
						way[i] = (way[i] + way[bel[v]]) % P;
				}
		f[i] += scc[i].size();
		if(f[i] > ans) {
			ans = f[i];
			w = 0;
		}
		if(f[i] == ans)
			w = (w + way[i]) % P;
		vis = 0;
	}
	cout << ans << '\n' << w;
	cout.flush();
	return 0;
}