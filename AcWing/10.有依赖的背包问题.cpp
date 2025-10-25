#include <bits/stdc++.h>
using namespace std;

constexpr const int N = 103;
vector<int> G[N];
int v[N], w[N], f[N][N], V;

void dfs(int u) {
	for(const auto& to: G[u]) {
		dfs(to);
		for(int j = V - v[u]; ~j; --j)
			for(int k = 0; k <= j; ++k)
				f[u][j] = max(f[u][j], f[u][j - k] + f[to][k]);
	}
	for(int j = V; j >= v[u]; --j)
		f[u][j] = f[u][j - v[u]] + w[u];
	for(int j = 0; j < v[u]; ++j)
		f[u][j] = 0;
}

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int n;
	cin >> n >> V;
	int rt = 0;
	for(int i = 1, fa; i <= n; ++i) {
		cin >> v[i] >> w[i] >> fa;
		if(~fa)
			G[fa].push_back(i);
		else
			rt = i;
	}
	dfs(rt);
	cout << f[rt][V] << endl;
	return 0;
}
