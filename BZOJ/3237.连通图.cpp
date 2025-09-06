#include <bits/stdc++.h>
using namespace std;
using ULL = unsigned long long;

constexpr const int N = 2e5 + 3;
struct BIT {
	ULL c[N]{};
	int lb(int x)
	{ return x & -x; }
	void mdf(int x, ULL w) {
		for(; x < N; x += lb(x))
			c[x] ^= w;
	}
	ULL qry(int x) {
		ULL res = 0;
		for(; x; x -= lb(x))
			res ^= c[x];
		return res;
	}
	ULL qry(int L, int R)
	{ return qry(R) ^ qry(L - 1); }
} T;
pair<int, int> e[N];
vector<int> G[N];
bitset<N> vis, onT;
int fa[N], dfn[N], sz[N], dep[N], pid[N], id[N], cnt;
ULL w[N];

void dfs(int u) {
	dfn[u] = ++cnt;
	sz[u] = 1;
	vis[u] = true;
	for(const auto& v: G[u]) {
		if(vis[v])
			continue;
		fa[v] = u;
		dep[v] = dep[u] + 1;
		dfs(v);
		sz[u] += sz[v];
	}
}

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	random_device sd;
	mt19937_64 rnd(sd());
	int n, m, _q;
	cin >> n >> m;
	for(int i = 1, u, v; i <= m; ++i) {
		cin >> u >> v;
		G[u].push_back(v);
		G[v].push_back(u);
		e[i] = {u, v};
		w[i] = rnd();
	}
	dep[1] = 1;
	dfs(1);
	for(int i = 1; i <= m; ++i) {
		auto [u, v] = e[i];
		if(fa[u] != v && fa[v] != u) {
			T.mdf(dfn[u], w[i]);
			T.mdf(dfn[v], w[i]);
		} else {
			onT[i] = true;
			pid[i] = (dep[u] < dep[v]? v: u);
		}
	}
	cin >> _q;
	for(; _q--; cout.put('\n')) {
		cin >> m;
		for(int i = 1; i <= m; ++i) {
			cin >> id[i];
			if(!onT[id[i]]) {
				T.mdf(dfn[e[id[i]].first], w[id[i]]);
				T.mdf(dfn[e[id[i]].second], w[id[i]]);
			}
		}
		bool flag = true;
		for(int S = 1; flag && S < 1 << m; ++S) {
			ULL t = 0; bool st = 0;
			for(int j = 1; j <= m; ++j) {
				if(!((S >> (j - 1)) & 1))
					continue;
				if(!onT[id[j]])
					continue;
				int v = pid[id[j]];
				ULL t2 = T.qry(dfn[v], dfn[v] + sz[v] - 1);
				t ^= t2;
				st = true;
			}
			if(st && !t)
				flag = false;
		}
		cout << (flag? "Connected": "Disconnected");
		for(int i = 1; i <= m; ++i)
			if(!onT[id[i]]) {
				T.mdf(dfn[e[id[i]].first], w[id[i]]);
				T.mdf(dfn[e[id[i]].second], w[id[i]]);
			}
	}
	cout.flush(); return 0;
}
