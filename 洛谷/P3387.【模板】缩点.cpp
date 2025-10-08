#include <bits/stdc++.h>
using namespace std;
using LL = long long;

constexpr const int N = 1e4 + 3;
vector<int> G[N];
stack<int> stk;
bool ins[N];
int a[N], dfn[N], low[N], bel[N], idx = 0, cnt = 0;
LL f[N];

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
		LL tot = f[++cnt] = 0;
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
	cin.tie(nullptr)->sync_with_stdio(false);
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
	cout << *max_element(f + 1, f + n + 1) << endl;
	return 0;
}
