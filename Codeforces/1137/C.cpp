#include <bits/stdc++.h>
using namespace std;

constexpr const int N = 1e5 + 3, D = 53, M = N * D;
vector<int> G[M], GC[M];
int stk[N], top = 0;
bitset<M> vis, ins;
bitset<N> day[D];
char s[D];
int low[M], dfn[M], bel[M], sz[M], f[M], n, d, idx = 0, cnt = 0;

int gw(int x)
{ return (x - 1) % n + 1; }

int gd(int x)
{ return (x - 1) / n + 1; }

void tarjan(int u) {
	low[u] = dfn[u] = ++idx;
	stk[++top] = u;
	ins[u] = true;
	for(const auto& v: G[u])
		if(!dfn[v]) {
			tarjan(v);
			low[u] = min(low[u], low[v]);
		} else if(ins[v])
			low[u] = min(low[u], dfn[v]);
	if(low[u] == dfn[u]) {
		++cnt;
		vector<int> c;
		while(top) {
			int v = stk[top--];
			ins[v] = false;
			c.push_back(v);
			bel[v] = cnt;
			if(!vis[gw(v)] && day[gd(v)][gw(v)]) {
				vis[gw(v)] = true;
				++sz[cnt];
			}
			if(v == u)
				break;
		}
		for(const auto& v: c)
			vis[gw(v)] = false;
	}
}

int get(int u) {
    if(ins[u])
		return f[u];
    for(const auto& v: GC[u])
		f[u] = max(get(v), f[u]);
    ins[u] = true;
    f[u] += sz[u];
    return f[u];
}

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int m;
	cin >> n >> m >> d;
	for(int u, v; m--; ) {
		cin >> u >> v;
		for(int j = 1; j <= d; ++j)
			G[n * (j - 1) + u].push_back(n * (j % d) + v);
	}
	for(int i = 1; i <= n; ++i) {
		cin >> s;
		for(int j = 1; j <= d; ++j)
			day[j][i] = (s[j - 1] == '1');
	}
	for(int u = 1; u <= n * d; ++u)
		if(!dfn[u])
			tarjan(u);
    for(int u = 1; u <= n * d; ++u)
		for(const auto& v: G[u])
			if(bel[u] != bel[v])
				GC[bel[u]].push_back(bel[v]);
	ins.reset();
	cout << get(bel[1]) << endl;
	return 0;
}
