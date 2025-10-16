#include <bits/stdc++.h>
using namespace std;

constexpr const int N = 1e5 + 3;
vector<int> G[N];
stack<int> stk;
bool ins[N];
int dfn[N], low[N], bel[N], sz[N], out[N], idx = 0, cnt = 0;

void dfs(int u) {
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
			int v = stk.top(); stk.pop();
			ins[v] = false;
			bel[v] = cnt;
			++sz[cnt];
			if(v == u)
				break;
		}
	}
}

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	for(int u, v; m--; ) {
		cin >> u >> v;
		G[u].push_back(v);
	}
	for(int i = 1; i <= n; ++i)
		if(!dfn[i])
			dfs(i);
	for(int u = 1; u <= n; ++u)
		for(const auto& v: G[u])
			if(bel[v] != bel[u])
				++out[bel[u]];
	int cntv = 0, cnts = 0;
	for(int i = 1; i <= cnt; ++i)
		if(out[i] == 0) {
			++cntv;
			cnts += sz[i];
		}
	cout << (cntv > 1? 0: cnts) << endl;
	return 0;
}
