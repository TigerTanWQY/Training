#include <bits/stdc++.h>
using namespace std;

constexpr const int N = 1e5 + 3;
vector<int> G[N];
int n, m, idx, fa[N][21], d[N], l[N], r[N], t[N];

void dfs(int u, int p) {
	d[u] = d[p] + 1;
	fa[u][0] = p;
	idx++;
	l[u] = idx;
	for(const auto& v: G[u])
		if(v != p)
			dfs(v, u);
	r[u] = idx;
}

int lca(int u, int v) {
	if(d[u] < d[v])
		swap(u, v);
	for(int k = 20; ~k; --k)
		if(d[u] - d[v] >= (1 << k))
			u = fa[u][k];
	if(u == v)
		return u;
	for(int k = 20; ~k; --k)
		if(fa[u][k] != fa[v][k]) {
			u = fa[u][k];
			v = fa[v][k];
		}
	return fa[u][0];
}

void add(int i, int d) {
	while(i <= n) {
		t[i] += d;
		i += i & -i;
	}
}

int sum(int i) {
	int s = 0;
	while(i > 0) {
		s += t[i];
		i -= i & -i;
	}
	return s;
}

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	cin >> n >> m;
	for(int i = 1, u, v; i <= n - 1; ++i) {
		cin >> u >> v;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	dfs(1, 0);
	for(int k = 1; k <= 20; ++k)
		for(int u = 1; u <= n; ++u)
			fa[u][k] = fa[fa[u][k - 1]][k - 1];
	for(int i = 1; i <= m; ++i) {
		char cmd; int u, v;
		cin >> cmd >> u >> v;
		if(cmd == 'P') {
			int p = lca(u, v);
			add(l[u], 1);
			add(l[v], 1);
			add(l[p], -2);
		} else {
			if(d[u] < d[v])
				u = v;
			cout << sum(r[u]) - sum(l[u]-1) << '\n';
		}
	}
	return 0;
}
