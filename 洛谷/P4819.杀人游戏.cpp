#include <iostream>
#include <iomanip>
#include <utility>
#include <vector>
#include <bitset>
#include <array>
#include <stack>
#include <set>
#include <algorithm>
using namespace std;

constexpr const int N = 100'003;
array<vector<int>, N> G, scc;
stack<int> stk;
bitset<N> ins;
array<int, N> dfn, low, bel, sz, din;
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
			++sz[cnt];
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
	for(int u, v; m--; ) {
		cin >> u >> v;
		G[u].push_back(v);
	}
	for(int u = 1; u <= n; ++u)
		if(!dfn[u])
			dfs(u);
	set<pair<int, int>> s;
	for(int u = 1; u <= n; ++u)
		for(const auto& v: G[u])
			if(bel[v] != bel[u] && !s.count({bel[v], bel[u]})) {
				++din[bel[v]];
				s.insert({bel[v], bel[u]});
			}
	int cnts = 0;
	for(int i = 1; i <= cnt; ++i)
		if(!din[i])
			++cnts;
	for(int i = 1; i <= cnt; ++i) {
		if(sz[i] != 1 || din[i])
			continue;
		bool flag = false;
		for(const auto& v: G[scc[i][0]])
			if(din[bel[v]] == 1)
				flag = true;
		if(!flag) {
			--cnts;
			break;
		}
	}
	cout << fixed << setprecision(6) << 1 - 1.0 * cnts / n;
	cout.flush();
	return 0;
}