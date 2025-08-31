#include <bits/stdc++.h>
using namespace std;

constexpr const int N = 2e5 + 3;
int n;
struct dsu {
	int fa[N];
	void init()
	{ fill(fa + 1, fa + n + 1, -1); }
	int fnd(const int u)
	{ return fa[u] < 0? u: fa[u] = fnd(fa[u]); }
	bool mrge(int u, int v) {
		if((u = fnd(u)) == (v = fnd(v)))
			return false;
		if(fa[u] > fa[v])
			swap(u, v);
		fa[u] += fa[v];
		fa[v] = u;
		return true;
	}
} all, ori;
vector<tuple<int, int, int>> e;
vector<int> G[N];
set<int> st;
long long tot, ans = 0;

void dfs(const int u) {
	st.erase(u);
	sort(G[u].begin(), G[u].end());
	for(int v = 0; ; ++v) {
		auto cit = st.lower_bound(v);
		if(cit == st.cend())
			return;
		v = *cit;
		if(!binary_search(G[u].cbegin(), G[u].cend(), v)) {
			all.mrge(u, v);
			dfs(v);
			--tot;
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int m;
	cin >> n >> m;
	tot = 1LL * n * (n - 1) / 2 - m;
	for(int i = 1; i <= n; ++i)
		st.insert(i);
	all.init(); ori.init();
	int C = 0;
	for(int u, v, w; m--; ) {
		cin >> u >> v >> w;
		G[u].push_back(v);
		G[v].push_back(u);
		C ^= w;
		e.push_back({w, u, v});
	}
	for(int i = 1; i <= n; ++i)
		if(st.count(i))
			dfs(i);
	if(tot > 0)
		C = 0;
	sort(e.begin(), e.end());
	for(const auto& [w, u, v]: e)
		if(all.mrge(u, v)) {
			ans += w;
			ori.mrge(u, v);
		} else if(ori.mrge(u, v))
			C = min(C, w);
	cout << ans + C << endl;
	return 0;
}
