#include <bits/stdc++.h>
using namespace std;

constexpr const int N = 4e5 + 3;
vector<int> G[N];
bool vis[N], f[N];
int ans[N];

void dfs1(int u) {
	f[u] = vis[u] = true;
	ans[u] = 1;
	for(const auto& v: G[u])
		if(!f[v])
			dfs1(v);
		else if(vis[v])
			ans[v] = -1;
		else if(ans[v] >= 0)
			ans[v] = 2;
	vis[u] = false;
}

void dfs2(int u, int t) {
	f[u] = true;
	if(ans[u] != -1)
		ans[u] = t;
	for(const auto& v: G[u])
		if(!f[v])
			dfs2(v, t);
}

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int _T;
	cin >> _T;
	for(int n, m; _T--; cout.put('\n')) {
		cin >> n >> m;
		for(int u, v; m--; ) {
			cin >> u >> v;
			G[u].push_back(v);
		}
		dfs1(1);
		for(int i = 1; i <= n; ++i)
			f[i] = 0;
		for(int i = 1; i <= n; ++i)
			if(ans[i] == 2)
				dfs2(i, 2);
		for(int i = 1; i <= n; ++i)
			f[i] = 0;
		for(int i = 1; i <= n; ++i)
			if(ans[i] == -1)
				dfs2(i, -1);
		for(int i = 1; i <= n; ++i)
			cout << ans[i] << ' ';
		for(int i = 1; i <= n; ++i) {
			G[i].clear();
			ans[i] = 0;
			vis[i] = f[i] = false;
		}
	}
	cout.flush(); return 0;
}
