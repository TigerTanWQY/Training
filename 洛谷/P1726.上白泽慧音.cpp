#include <iostream>
#include <vector>
#include <bitset>
#include <stack>
#include <array>
#include <algorithm>
using namespace std;

constexpr const int N = 5'003;
vector<vector<int>> scc;
array<vector<int>, N> G;
stack<int> stk;
bitset<N> ins;
array<int, N> low, dfn;
int idx = 0;

void dfs(const int& u) {
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
		sort(c.begin(), c.end());
		scc.push_back(c);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, m;
	cin >> n >> m;
	for(int u, v, type; m--; ) {
		cin >> u >> v >> type;
		G[u].push_back(v);
		if(type == 2)
			G[v].push_back(u);
	}
	for(int u = 1; u <= n; ++u)
		if(!dfn[u])
			dfs(u);
	sort(scc.begin(), scc.end());
	int maxw = 0, ansi = 0;
	for(int i = 0; i < scc.size(); ++i)
		if(scc[i].size() > maxw) {
			maxw = scc[i].size();
			ansi = i;
		}
	cout << maxw << '\n';
	for(const auto& u: scc[ansi])
		cout << u << ' ';
	cout.flush();
	return 0;
}