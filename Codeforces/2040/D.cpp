#include <bits/stdc++.h>
using namespace std;

constexpr const int N = 2e5 + 3;
vector<int> G[N];
int ans[N], tot;

void dfs(int u, int fa) {
	bool flg = false;
	ans[u] = ++tot;
	for(const auto& v: G[u]) {
		if(v == fa)
			continue;
		if(!flg) {
			dfs(v, u);
			flg = true;
			continue;
		}
		if(tot + 1 - ans[u] == 2)
			tot = ans[u] + 3;
		else if((tot + 1 - ans[u]) & 1)
			++tot;
		dfs(v, u);
	}
}

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int _T;
	cin >> _T;
	for(int n; _T--; cout.put('\n')) {
		cin >> n;
		tot = 0;
		for(int i = 1; i <= n; ++i)
			G[i].clear();
		for(int i = 1, u, v; i < n; ++i) {
			cin >> u >> v;
			G[u].push_back(v);
			G[v].push_back(u);
		}
		dfs(1, 0);
		for(int i = 1; i <= n; ++i)
			cout << ans[i] << ' ';
	}
	cout.flush(); return 0;
}
