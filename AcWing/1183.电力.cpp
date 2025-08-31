#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

constexpr const int N = 10'003;
vector<int> G[N];
int low[N], dfn[N], idx = 0, ans = 0;

void dfs(const int u, const int rt) {
	low[u] = dfn[u] = ++idx;
	int cnt = 0;
	for(const auto& v: G[u])
		if(!dfn[v]) {
			dfs(v, rt);
			low[u] = min(low[u], low[v]);
			if(low[v] >= dfn[u])
				++cnt;
		} else
			low[u] = min(low[u], dfn[v]);
	if(u != rt)
		++cnt;
	ans = max(ans, cnt);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	for(int n, m, cnt = 0; cin >> n >> m && (n || m); cout << '\n') {
		for(int _ = 0, u, v; _ < m; ++_) {
			cin >> u >> v;
			++u; ++v;
			G[u].push_back(v);
			G[v].push_back(u);
		}
		for(int i = 1; i <= n; ++i)
			if(!dfn[i]) {
				++cnt;
				dfs(i, i);
			}
		cout << ans + cnt - 1;
		for(int i = 1; i <= n; ++i) {
			G[i].clear();
			low[i] = dfn[i] = 0;
		}
		idx = ans = cnt = 0;
	}
	cout.flush();
	return 0;
}