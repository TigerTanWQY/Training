#include <bits/stdc++.h>
using namespace std;

constexpr const int N = 2e6 + 3; // 2倍空间
vector<int> G[N];
stack<int> stk;
bool ins[N];
int low[N], dfn[N], bel[N], idx = 0, cnt = 0;

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
		++cnt;
		while(!stk.empty()) {
			int v = stk.top(); stk.pop();
			ins[v] = false;
			bel[v] = cnt;
			if(v == u)
				break;
		}
	}
}

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	for(int u, x, v, y; m--; ) {
		cin >> u >> x >> v >> y;
		G[u + (x ^ 1) * n].push_back(v + y * n);
		G[v + (y ^ 1) * n].push_back(u + x * n);
	}
	for(int i = 1; i <= n * 2; ++i)
		if(!dfn[i])
			dfs(i);
	for(int i = 1; i <= n; ++i)
		if(bel[i] == bel[i + n]) {
			cout << "IMPOSSIBLE" << endl;
			return 0;
		}
	cout << "POSSIBLE\n";
	for(int i = 1; i <= n; ++i)
		cout << (bel[i] > bel[i + n]) << ' ';
	cout << endl; return 0;
}
