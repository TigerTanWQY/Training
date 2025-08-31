#include <iostream>
#include <vector>
#include <bitset>
#include <stack>
#include <array>
#include <algorithm>
using namespace std;

constexpr const int N = 2'000'003;
array<vector<int>, N> G;
stack<int> stk;
bitset<N> ins;
array<int, N> low, dfn, bel;
int idx = 0, cnt = 0;

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
		++cnt;
		while(!stk.empty()) {
			int v = stk.top();
			stk.pop();
			ins[v] = false;
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
	for(int u, x, v, y; m--; ) {
		cin >> u >> x >> v >> y;
		G[u + (x ^ 1) * n].push_back(v + y * n);
		G[v + (y ^ 1) * n].push_back(u + x * n);
	}
	for(int i = 1; i <= 2 * n; ++i)
		if(!dfn[i])
			dfs(i);
	for(int u = 1; u <= n; ++u) // 判无解
		if(bel[u] == bel[u + n]) {
			cout << "IMPOSSIBLE";
			return 0;
		}
	cout << "POSSIBLE\n";
	for(int u = 1; u <= n; u++)
		cout << (bel[u] > bel[u + n]) << ' ';
	cout.flush();
	return 0;
}