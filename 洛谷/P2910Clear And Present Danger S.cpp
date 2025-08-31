#include <iostream>
using namespace std;

const int N = 103;
int v[N * N], f[N][N];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m;
	cin >> n >> m;
	for(int i = 1; i <= m; ++i)
		cin >> v[i];
	for(int i = 1; i <= n; ++i)
		for(int j = 1; j <= n; ++j)
			cin >> f[i][j];
	for(int k = 1; k <= n; ++k)
		for(int i = 1; i <= n; ++i)
			for(int j = 1; j <= n; ++j)
				f[i][j] = min(f[i][j], f[i][k] + f[k][j]);
	int ans = 0;
	for(int i = 1; i < m; ++i)
		ans += f[v[i]][v[i + 1]];
	cout << ans;
	return 0;
}