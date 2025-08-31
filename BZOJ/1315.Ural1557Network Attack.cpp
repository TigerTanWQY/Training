#include <iostream>
#include <utility>
#include <vector>
#include <bitset>
#include <array>
#include <algorithm>
using namespace std;

constexpr const int N = 2'003;
constexpr const int M = 200'003;
struct Edge
{ int u, v; }
e[M];
vector<pair<int, int>> G[N];
bitset<M> vise, isb, isbe;
array<int, N> low, dep, high, c, fa;
int tot = 0;
long long ans;

int dfs(const int& u, const int& fau) {
	low[u] = dep[u] = dep[fau] + 1;
	c[u] = 0;
	fa[u] = fau;
	for(const auto& [v, id]: G[u])
		if(!vise[id]) {
			vise[id] = true;
			if(dep[v] == 0) {
				low[u] = min(low[u], dfs(v, u));
				c[u] += c[v];
				if(low[v] == dep[v]) {
					isb[id] = true;
					++tot;
				}
			} else {
				low[u] = min(low[u], dep[v]);
				isbe[id] = true;
				--c[v];
				++c[u];
			}
		}
	return low[u];
}

void upd(int u, int v) {
	if(dep[u] > dep[v])
		swap(u, v);
	while(v != u) {
		high[v] = max(high[v], dep[u]);
		v = fa[v];
	}
}

int cal(const int& u) {
	if(high[u] == 0)
		return 0;
	int cnt = 0, v = fa[u];
	while(dep[v] != high[u]) {
		if(c[u] == c[v])
			++cnt;
		v = fa[v];
	}
	return cnt;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, m;
	cin >> n >> m;
	for(int i = 1; i <= m; ++i) {
		cin >> e[i].u >> e[i].v;
		G[e[i].u].push_back({e[i].v, i});
		G[e[i].v].push_back({e[i].u, i});
	}
	dfs(1, 0);
	ans += 1LL * tot * (tot - 1) / 2;
	ans += 1LL * tot * (m - tot);
	for(int u = 1; u <= n; ++u)
		if(c[u] == 1)
			++ans;
	for(int i = 1; i <= m; ++i)
		if(isbe[i])
			upd(e[i].u, e[i].v);
	for(int u = 1; u <= n; ++u)
		ans += cal(u);
	cout << ans;
	cout.flush();
	return 0;
}