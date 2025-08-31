#include <iostream>
#include <vector>
#include <bitset>
#include <stack>
#include <algorithm>
using namespace std;

const int N = 10003;
vector<vector<int>> scc;
vector<int> G[N];
stack<int> stk;
bitset<N> ins;
int dfn[N], low[N], bel[N], idx = 0, cnt = 0;

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
		vector<int> c;
		while(!stk.empty()) {
			int v = stk.top();
			stk.pop();
			ins[v] = false;
			bel[v] = cnt;
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
	for(int u, v; m--; ) {
		cin >> u >> v;
		G[u].push_back(v);
	}
	for(int u = 1; u <= n; ++u)
		if(!dfn[u])
			dfs(u);
	sort(scc.begin(), scc.end());
	cout << scc.size() << '\n';
	for(const auto& c: scc) {
		for(const auto& u: c)
			cout << u << ' ';
		cout << '\n';
	}
	cout.flush();
	return 0;
}