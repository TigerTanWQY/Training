#include <bits/stdc++.h>
using namespace std;

constexpr const int N = 2e5 + 3;
vector<int> G[N], his;
int fa[N], d[N], a[N], b[N], ans[N], n, tot;

stack<tuple<int, int, int, int, int, int, int>> stk;
int fnd(int u) { return fa[u] >= 0? fnd(fa[u]): u; }
void mrge(int u, int v) {
	u = fnd(u); v = fnd(v);
	if(u == v) {
		stk.push({u, fa[u], v, fa[v], d[u], d[v], tot});
		tot -= min(-fa[u], d[u]);
		++d[u];
		tot += min(-fa[u], d[u]);
		return;
	}
	if(-fa[u] < -fa[v])
		swap(u, v);
	stk.push({u, fa[u], v, fa[v], d[u], d[v], tot});
	tot -= min(-fa[u], d[u]); tot -= min(-fa[v], d[v]);
	fa[u] += fa[v]; fa[v] = u;
	d[u] += d[v] + 1;
	tot += min(-fa[u], d[u]);
}
void undo() {
	assert(!his.empty());
	int lst = his.back();
	his.pop_back();
	while(stk.size() > lst) {
		auto [u, x, v, y, ca, cb, res] = stk.top(); stk.pop();
		fa[u] = x; fa[v] = y;
		d[u] = ca; d[v] = cb;
		tot = res;
	}
}
void mkhis()
{ his.push_back(stk.size()); }

void dfs(int u, int p) {
	mkhis(); mrge(a[u], b[u]);
	ans[u] = tot;
	for(const auto& v: G[u]) {
		if(v == p)
			continue;
		dfs(v, u);
	}
	undo();
}

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	memset(fa, -1, sizeof(fa));
	cin >> n;
	for(int i = 0; i < n; i++)
	{ cin >> a[i] >> b[i]; --a[i]; --b[i]; }
	for(int i = 0, u, v; i < n - 1; i++) {
		cin >> u >> v; --u; --v;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	dfs(0, -1);
	for(int i = 1; i < n; i++)
		cout << ans[i] << ' ';
	cout << endl; return 0;
}
