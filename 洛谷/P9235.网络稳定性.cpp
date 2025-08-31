#include <bits/stdc++.h>
using namespace std;

constexpr const int N = 1e5 + 3;
vector<tuple<int, int, int>> e;
int dsu[N << 1], fa[21][N << 1], V[N << 1], dep[N << 1], n;

int fnd(int x) {
	if(dsu[x] != x)
		dsu[x] = fnd(dsu[x]);
	return dsu[x];
}

void dfs(int u) {
	if(dep[u])
		return;
	else if(!fa[0][u]) {
		dep[u] = 1;
		return;
	}
	dfs(fa[0][u]);
	dep[u] = dep[fa[0][u]] + 1;
}

int LCA(int u, int v) {
	if(dep[u] < dep[v])
		swap(u,v);
	for(int j = 18; ~j; --j)
		if(dep[fa[j][u]] >= dep[v])
			u = fa[j][u];
	if(u == v)
		return u;
	for(int j = 18; ~j; --j)
		if(fa[j][u] != fa[j][v]) {
			u = fa[j][u];
			v = fa[j][v];
		}
	return fa[0][u];
}

void Kruskal() {
	sort(begin(e), end(e), greater<>());
	for(int i = 0; i < 2 * n; ++i)
		dsu[i] = i;
	int cnt = n;
	for(auto [w, u, v]: e) {
		u = fnd(u); v = fnd(v);
		if(u == v)
			continue;
		dsu[u] = dsu[v] = fa[0][u] = fa[0][v] = ++cnt;
		V[cnt] = w;
		if(cnt == 2 * n - 1)
			break;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int m, q;
	cin >> n >> m >> q;
	for(int u, v, w; m--; ) {
		cin >> u >> v >> w;
		e.push_back({w, u, v});
	}
	Kruskal();
	for(int j = 1; j <= 18; ++j)
		for(int i = 1; i < 2 * n; ++i)
			fa[j][i] = fa[j - 1][fa[j - 1][i]];
    dep[2 * n - 1] = 1;
	for(int i = 1; i < 2 * n; ++i)
		dfs(i);
	for(int u, v; q--; cout.put('\n')) {
		cin >> u >> v;
		if(fnd(u) != fnd(v))
			cout << "-1";
		else
			cout << V[LCA(u, v)];
	}
	cout.flush();
	return 0;
}
