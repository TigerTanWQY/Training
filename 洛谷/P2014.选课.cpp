#include <iostream>
#include <vector>
using namespace std;

constexpr const int N = 303;
vector<int> G[N];
int f[N][N], m;

void dfs(const int u) {
	for(const auto& v: G[u])
		dfs(v);
	for(const auto& v: G[u])
		for(int j = m; j; --j)
			for(int k = 0; k < j; ++k)
				if(f[u][j - k] + f[v][k] > f[u][j])
					f[u][j] = f[u][j - k] + f[v][k];
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	cin >> n >> m;
	++m;
	for(int i = 1, fa; i <= n; ++i) {
		cin >> fa >> f[i][1];
		G[fa].push_back(i);
	}
	dfs(0);
	cout << f[0][m];
	return 0;
}