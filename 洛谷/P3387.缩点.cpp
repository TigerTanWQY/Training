#include <iostream>
#include <vector>
#include <bitset>
#include <stack>
#include <array>
#include <algorithm>
using namespace std;
using LL = long long;

constexpr const int N = 10'003;
array<vector<int>, N> G;
bitset<N> ins;
stack<int> stk;
array<LL, N> f;
array<int, N> dfn, low, bel, a;
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
		LL tot = 0;
		f[cnt] = 0;
		while(!stk.empty()) {
			int v = stk.top();
			stk.pop();
			ins[v] = false;
			bel[v] = cnt;
			tot += a[v];
			for(const auto& x: G[v])
				if(bel[x] && bel[x] != cnt)
					f[cnt] = max(f[cnt], f[bel[x]]);
			if(v == u)
				break;
		}
		f[cnt] += tot;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, m;
	cin >> n >> m;
	for(int i = 1; i <= n; ++i)
		cin >> a[i];
	for(int u, v; m--; ) {
		cin >> u >> v;
		G[u].push_back(v);
	}
	for(int u = 1; u <= n; ++u)
		if(!dfn[u])
			dfs(u);
	LL ans = 0;
	for(int u = 1; u <= n; ++u)
		ans = max(ans, f[u]);
	cout << ans;
	cout.flush();
	return 0;
}