#include <bits/stdc++.h>
using namespace std;
#define int long long

constexpr const int N = 2e5 + 3;
tuple<int, int, int, int, int, bool> E[N];
vector<pair<int, int>> G[N];
pair<int, int> st[21][N];
int n, m, tc[N], tw[N], pa[N], lg2[N],
	dep[N], siz[N], son[N], fa[N], wei[N],
	dfn[N], adfn[N], top[N], tot = 0;

int fnd(int x)
{ return x == pa[x]? x: pa[x] = fnd(pa[x]); }

void dfs1(int u, int ft) {
	dep[u] = dep[fa[u] = ft] + 1;
	siz[u] = 1;
	for(const auto& [v, w]: G[u]) {
		if(v == ft)
			continue;
		dfs1(v,u); wei[v] = w;
		siz[u] += siz[v];
		if(siz[v] > siz[son[u]])
			son[u] = v;
	}
}

void dfs2(int u, int tp) {
	adfn[dfn[u] = ++tot] = u; top[u] = tp;
	if(son[u])
		dfs2(son[u],tp);
	for(const auto& [v, w]: G[u])
		if(!top[v])
			dfs2(v, v);
}

auto qry = [](int L, int R) {
	int k = lg2[R - L + 1];
	return max(st[k][L], st[k][R - (1 << k) + 1]);
};

auto LCA = [](int u, int v) {
	pair<int, int> res;
	while(top[u] != top[v]) {
		if(dep[top[u]] < dep[top[v]])
			swap(u,v);
		res = max(res, qry(dfn[top[u]], dfn[u]));
		u = fa[top[u]];
	}
	if(dep[u] > dep[v])
		swap(u,v);
	return max(res, qry(dfn[u] + 1, dfn[v]));
};

auto MST = [](void) {
	iota(pa, pa + n + 1, 0);
	sort(E + 1, E + m + 1);
	long long res = 0;
	for(int i = 1; i <= m; ++i) {
		auto& [w, u, v, c, I, f] = E[i];
		int fu = fnd(u), fv = fnd(v);
		if(fu == fv)
			continue;
		G[u].push_back({v, w});
		G[v].push_back({u, w});
		pa[fu] = fv; res += w; f = true;
	}
	return res;
};

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n >> m;
	for(int i = 1; i <= m; ++i)
		cin >> tw[i];
	for(int i = 1; i <= m; ++i)
		cin >> tc[i];
	for(int i = 1, u, v; i <= m; ++i) {
		cin >> u >> v;
		E[i] = {tw[i], u, v, tc[i], i, false};
	}
	int S;
	cin >> S;
	auto res = MST(), ans = res;
	dfs1(1, 0); dfs2(1, 1);
	for(int i = 2; i <= n; ++i)
		lg2[i] = lg2[i >> 1] + 1;
	for(int i = 1; i <= n; ++i)
		st[0][i] = {wei[adfn[i]], adfn[i]};
	for(int j = 1; 1 << j <= n; ++j)
		for(int i = 1; i + (1 << j) - 1 <= n; ++i)
			st[j][i] = max(st[j - 1][i], st[j - 1][i + (1 << j - 1)]);
	int id1, id2;
	for(int i = 1; i <= m; ++i) {
		const auto& [w, u, v, c, I, f] = E[i];
		auto [x, y] = LCA(u, v);
		auto cur = res - (S / c);
		if(!f)
			cur += w - x;
		if(cur < ans) {
			ans = cur; id1 = i;
			if(!f)
				id2 = y;
		}
	}
	cout << ans << '\n';
	for(int i = 1; i <= m; ++i) {
		const auto& [w, u, v, c, I, f] = E[i];
		if(i == id1)
			cout << I << ' ' << w - (S / c) << '\n';
		else if(f && id2 != (fa[u] == v? u: v))
			cout << I << ' ' << w << '\n';
	}
	cout.flush();
	return 0;
}
