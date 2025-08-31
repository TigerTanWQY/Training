#include <iostream>
#include <vector>
#include <bitset>
#include <stack>
#include <array>
#include <algorithm>
using namespace std;
using LL = long long;

constexpr const int N = 500'003;
array<vector<int>, N> G;
bitset<N> ins, b;
stack<int> stk;
array<int, N> dfn, low, bel, a;
array<LL, N> f;
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
		bool flag = false;
		f[cnt] = -0x3f3f3f3f3f3f3f3f;
		while(!stk.empty()) {
			int v = stk.top();
			stk.pop();
			ins[v] = false;
			bel[v] = cnt;
			tot += a[v];
			flag |= b[v];
			for(const auto& x: G[v])
				if(bel[x] && bel[x] != cnt)
					f[cnt] = max(f[cnt], f[bel[x]]);
			if(v == u)
				break;
		}
		if(flag)
			f[cnt] = max(f[cnt], 0LL);
		f[cnt] += tot;
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
	for(int i = 1; i <= n; ++i)
		cin >> a[i];
	int s, _T;
	cin >> s >> _T;
	for(int x; _T--; ) {
		cin >> x;
		b[x] = true;
	}
	dfs(s);
	cout << f[bel[s]];
	cout.flush();
	return 0;
}