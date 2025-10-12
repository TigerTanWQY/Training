#include <bits/stdc++.h>
using namespace std;

constexpr const int N = 3e5 + 3;
vector<pair<int, bool>> G[N], Ge[N];
tuple<int, int, int> E[N];
stack<int> stk;
bool ins[N], ise[N], vis[N];
int dfn[N], low[N], bel[N], ed, idx = 0, cnt = 0;

void tarjan(int u, int fa) {
	dfn[u] = low[u] = ++idx;
	stk.push(u); ins[u] = true;
	for(const auto& [v, w]: G[u]) {
		if(v == fa)
			continue;
		if(!dfn[v]) {
			tarjan(v, u);
			low[u] = min(low[u], low[v]);
		} else if(ins[v])
			low[u] = min(low[u], dfn[v]);
	}
	if(dfn[u] == low[u]) {
		bel[u] = ++cnt;
		for(; stk.top() != u; stk.pop()) {
			bel[stk.top()] = cnt;
			ins[stk.top()] = false;
		}
		stk.pop(); ins[u] = false;
	}
}

void dfs(int u, bool f) {
	if(ise[u])
		f = 1;
	if(u == ed) {
		cout << (f? "YES": "NO") << endl;
		exit(0);
		return;
	}
	vis[u] = true;
	for(const auto& [v, w]: Ge[u])
		if(!vis[v])
			dfs(v, f | w);
}

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int n, m, st;
	cin >> n >> m;
	for(int i = 1, u, v, w; i<=m; ++i) {
		cin >> u >> v >> w;
		E[i] = {u, v, w};
		G[u].push_back({v, w});
		G[v].push_back({u, w});
	}
	tarjan(1, 0);
	for(int i = 1; i <= m; ++i) {
		auto [u, v, w] = E[i];
		if(bel[u] == bel[v] && w)
			ise[bel[u]] = true;
	}
	for(int i = 1; i <= m; ++i) {
		auto [u, v, w] = E[i];
		if(bel[u] != bel[v]) {
			Ge[bel[u]].push_back({bel[v], w});
			Ge[bel[v]].push_back({bel[u], w});
		}
	}
	cin >> st >> ed;
	st = bel[st]; ed = bel[ed];
	dfs(st, 0);
	return 0;
}
