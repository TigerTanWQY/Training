#include <bits/stdc++.h>
using namespace std;

constexpr const int N = 5003;
vector<vector<int>> scc;
vector<int> G[N];
stack<int> stk;
bool ins[N];
int low[N], dfn[N], idx = 0;

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
	if(low[u] == dfn[u]) {
		vector<int> c;
		while(!stk.empty()) {
			int v = stk.top();
			stk.pop();
			ins[v] = false;
			c.push_back(v);
			if(v == u)
				break;
		}
		sort(begin(c), end(c));
		scc.push_back(c);
	}
}

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	for(int u, v, tp; m--; ) {
		cin >> u >> v >> tp;
		G[u].push_back(v);
		if(tp == 2)
			G[v].push_back(u);
	}
	for(int i = 1; i <= n; ++i)
		if(!dfn[i])
			dfs(i);
	sort(begin(scc), end(scc));
	int maxw = 0, ansi = 0;
	for(int i = 0; i < scc.size(); ++i)
		if(scc[i].size() > maxw) {
			maxw = scc[i].size();
			ansi = i;
		}
	cout << maxw << '\n';
	for(const auto& u: scc[ansi])
		cout << u << ' ';
	cout << endl; return 0;
}
