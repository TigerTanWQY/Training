#include <bits/stdc++.h>
using namespace std;

constexpr const int N = 1e5 + 3;
vector<int> G[N];
int a[N], f[N];

void dfs(int u, int fa) {
	if(f[u])
		return;
	f[u] = 1;
	for(const auto& v: G[u]) {
		if(v == fa)
			continue;
		if(a[u] > a[v])
		{ dfs(v, u); f[u] += f[v]; }
	}
}

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int n;
	cin >> n;
	for(int i = 1; i <= n; ++i)
		cin >> a[i];
	for(int _ = 1, u, v; _ < n; ++_) {
		cin >> u >> v;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	for(int i = 1; i <= n; ++i)
		if(!f[i])
			dfs(i, 0);
	cout << *max_element(f + 1, f + n + 1) << endl;
	return 0;
}
