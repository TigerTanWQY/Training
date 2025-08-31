#include <iostream>
#include <vector>
#include <bitset>
#include <stack>
#include <algorithm>
using namespace std;

const int N = 10'003;
vector<int> G[N];
bitset<N> ins;
stack<int> stk;
int dfn[N], low[N], bel[N], sz[N], dout[N], idx = 0, cnt = 0;

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
			bel[v] = cnt;
			++sz[cnt]; //!
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
	for(int u = 1; u <= n; ++u)
		for(const auto& v: G[u])
			if(bel[u] != bel[v])
				++dout[bel[u]];
	int cntv = 0, cnts = 0;
	for(int i = 1; i <= cnt; ++i)
		if(dout[i] == 0) {
			++cntv;
			cnts += sz[i];
		}
	if(cntv > 1)
		cout << '0';
	else
		cout << cnts;
	cout.flush();
	return 0;
}