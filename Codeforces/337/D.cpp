#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

constexpr const int N = 100'003;
vector<int> G[N];
int a[N], f[N];

void dfs(const int u, const int fa, const int d) {
	f[u] = max(f[u], d);
	for(const auto& v: G[u])
		if(v != fa)
			dfs(v, u, d + 1);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, m, d;
	cin >> n >> m >> d;
	for(int i = 0; i < m; ++i)
		cin >> a[i];
	for(int _ = 1, u, v; _ < n; ++_) {
		cin >> u >> v;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	dfs(a[0], 0, 0);
	for(int k = 0; k < 2; ++k) {
		int u = a[0];
		for(int i = 1; i < m; ++i)
			if(f[a[i]] > f[u])
				u = a[i];
		dfs(u, 0, 0);
	}
	int ans = 0;
	for(int i = 1; i <= n; ++i)
		if(f[i] <= d)
			++ans;
	cout << ans;
	cout.flush();
	return 0;
}