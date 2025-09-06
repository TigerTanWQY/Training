#include <bits/stdc++.h>
using namespace std;
using LL = long long;

constexpr const int P = 998'244'353, N = 1e5 + 3;
vector<int> G[N];
bitset<N> vis;
LL f[N], g[N];
int ind[N], n;

void topo_sort() {
	queue<int> q;
	for(int i = 1; i <= n; ++i)
		if(!ind[i])
			q.push(i);
	while(!q.empty()) {
		int u = q.front();
		q.pop();
		if(vis[u])
			continue;
		vis[u] = true;
		for(const auto& v: G[u]) {
			if(!--ind[v])
				q.push(v);
			f[v] = (f[v] + f[u] + g[u]) % P;
			g[v] = (g[v] + g[u]) % P;
		}
	}
}

LL qpow(LL a, LL b) {
	LL res = 1;
	for(; b; a = a * a % P, b >>= 1)
		if(b & 1)
			res = res * a % P;
	return res;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int m;
	cin >> n >> m;
	for(int i = 1, u, v; i <= m; ++i) {
		cin >> u >> v;
		G[u].push_back(v);
		++ind[v];
	}
	for(int i = 1; i <= n; ++i)
		g[i] = 1;
	topo_sort();
	LL tf = 0, ts = 0;
	for(int i = 1; i <= n; ++i)
		tf = (tf + f[i]) % P;
	for(int i = 1; i <= n; ++i)
		ts = (ts + g[i]) % P;
	cout << (tf * qpow(ts, P - 2)) % P << endl;
	return 0;
}
