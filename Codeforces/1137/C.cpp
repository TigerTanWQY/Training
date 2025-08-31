#include <iostream>
#include <string>
#include <vector>
#include <bitset>
#include <algorithm>
using namespace std;

constexpr const int N = 100'003, D = 53, M = N * D;
vector<int> G[N], GC[N];
int stk[M], top = 0;
bitset<M> ins, vis;
bitset<N> day[D];
int low[M], dfn[M], bel[M], sz[M], f[M];
int n, d, idx = 0, cnt = 0;

int gw(const int& x)
{ return (x - 1) % n + 1; }

int gd(const int& x)
{ return (x - 1) / n + 1; }

void tarjan(const int& u) {
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

int get(const int& u) {
    if(ins[u])
		return f[u];
    for(const auto& v: GC[u])
		f[u] = max(get(v), f[u]);
    ins[u] = true;
    f[u] += sz[u];
    return f[u];
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int m;
	cin >> n >> m >> d;
	for(int u, v; m--; ) {
		cin >> u >> v;
		for(int j = 1; j <= d; ++j)
			G[n * (j - 1) + u].push_back(n * (j % d) + v);
	}
	for(int i = 1; i <= n; ++i) {
		string s;
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
	cout << get(bel[1]);
	cout.flush();
	return 0;
}