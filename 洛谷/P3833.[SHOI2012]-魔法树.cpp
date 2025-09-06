#include <bits/stdc++.h>
using namespace std;
using LL = long long;

constexpr const int MN = 1e5 + 3;
int n, fa[MN], son[MN], bro[MN], in[MN], out[MN], tot = 0, dep[MN];

void dfs(int u) {
	in[u] = ++tot; dep[u] = dep[fa[u]] + 1;
	for(int v = son[u]; v; v = bro[v])
		dfs(v);
	out[u] = tot;
}
namespace LCA {
	int sz[MN], hev[MN], top[MN];
	void dfs1(int u) {
		sz[u] = 1; int mx = -1e5 - 3;
		for(int v = son[u]; v; v = bro[v]) {
			dfs1(v); sz[u] += sz[v];
			if(mx < sz[v])
			{ mx = sz[v]; hev[u] = v; }
		}
	}
	void dfs2(int u, int ct) {
		top[u] = ct;
		if(hev[u])
			dfs2(hev[u], ct);
		for(int v = son[u]; v; v = bro[v])
			if(v != hev[u])
				dfs2(v,v);
	}
	int lca(int u, int v) {
		while(top[u] != top[v]) {
			if(dep[top[u]] < dep[top[v]])
				swap(u,v);
			u = fa[top[u]];
		}
		return dep[u] > dep[v]? v: u;
	}
}
using LCA::dfs1, LCA::dfs2, LCA::lca;
struct BIT {
	LL t[MN];
	int lb(int x)
	{ return x & -x; }
	void mdf(int x, LL y)
	{ for(; x <= n; x += lb(x)) t[x] += y; }
	LL qry(int x) {
		LL res = 0;
		for(; x; x -= lb(x))
			res += t[x];
		return res;
	}
} T1, T2;
void mdf(int u, int v, LL d) {
	int lc = lca(u, v), lcf = fa[lc];
	T1.mdf(in[u], d * dep[u]); T1.mdf(in[v], d * dep[v]);
	T1.mdf(in[lc], -d * dep[lc]);
	T2.mdf(in[u], d); T2.mdf(in[v], d);
	T2.mdf(in[lc], -d);
	if(!lcf)
		return;
	T1.mdf(in[lcf], -d * dep[lcf]);
	T2.mdf(in[lcf], -d);
}
LL qry(int u) {
	LL res = T1.qry(out[u]) - T1.qry(in[u] - 1);
	res -= (dep[u] - 1) * (T2.qry(out[u]) - T2.qry(in[u] - 1));
	return res;
}
signed main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int _q;
	cin >> n;
	for(int i = 1, pa, u; i < n; ++i) {
		cin >> pa >> u; ++pa; ++u;
		fa[u] = pa; bro[u] = son[pa]; son[pa] = u;
	}
	cin >> _q;
	dfs(1); dfs1(1); dfs2(1, 1);
	for(char op; _q--; ) {
		cin >> op;
		if(op == 'Q') {
			int u;
			cin >> u; ++u;
			cout << qry(u) << '\n';
		} else {
			int u, v; LL d;
			cin >> u >> v >> d; ++u; ++v;
			mdf(u, v, d);
		}
	}
	cout.flush(); return 0;
}
