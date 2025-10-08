#include <bits/stdc++.h>
using namespace std;

constexpr const int N = 5e5 + 3, M = 2e6 + 3;
vector<vector<int>> eDCC;
vector<pair<int, int>> G[N];
pair<int, int> E[M];
stack<int> stk;
bool vis[N], ins[M];
int dfn[N], low[N], idx = 0;

void dfs(int u) {
	dfn[u] = low[u] = ++idx;
	stk.push(u);
	vis[u] = true;
	for(const auto& [v, id]: G[u]) {
		if(ins[id])
			continue;
		else
			ins[id] = true;
		if(!dfn[v]) {
			dfs(v);
			low[u] = min(low[u], low[v]);
		} else if(vis[v])
			low[u] = min(low[u], dfn[v]);
	}
	if(dfn[u] == low[u]) {
		vector<int> c;
		while(!stk.empty()) {
			int v = stk.top();
			stk.pop();
			c.push_back(v);
			if(v == u)
				break;
		}
		eDCC.push_back(c);
	}
}

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	for(int i = 1; i <= m; ++i) {
		cin >> E[i].first >> E[i].second;
		G[E[i].first].push_back({E[i].second, i});
		G[E[i].second].push_back({E[i].first, i});
	}
	for(int u = 1; u <= n; ++u)
		if(!vis[u])
			dfs(u);
	cout << eDCC.size() << '\n';
	for(const auto& c: eDCC) {
		cout << c.size() << ' ';
		for(const auto& u: c)
			cout << u << ' ';
		cout.put('\n');
	}
	cout.flush(); return 0;
}
