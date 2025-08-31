#include <iostream>
#include <string>
#include <vector>
#include <bitset>
#include <stack>
#include <array>
#include <algorithm>
using namespace std;

constexpr const int N = 1'003;
array<vector<int>, N> G, G0, scc;
stack<int> stk;
bitset<N> ins;
array<int, N> low, dfn, bel;
int idx = 0, cnt = 0;

void dfs(const int& u) {
	low[u] = dfn[u] = ++idx;
	stk.push(u);
	ins[u] = true;
	for(const auto& v: G0[u])
		if(!dfn[v]) {
			dfs(v);
			low[u] = min(low[u], low[v]);
		} else if(ins[v])
			low[u] = min(low[u], dfn[v]);
	if(low[u] == dfn[u]) {
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
	int n, m;
	cin >> n >> m;
	for(int u, v, w; m--; ) {
		cin >> u >> v >> w;
		G[u].push_back(v);
		if(w == 0)
			G0[u].push_back(v);
	}
	for(int u = 1; u <= n; ++u)
		if(!dfn[u])
			dfs(u);
	bitset<N> ans(string(N, '1'));
	for(int i = 1; i <= cnt; ++i)
		if(scc[i].size() > 1)
			for(const auto& u: scc[i]) {
				ans[u] = false;
				for(const auto& v: G[u])
					ans[v] = false;
			}
	for(int u = 1; u <= n; ++u)
		cout << ans[u] << '\n';
	cout.flush();
	return 0;
}