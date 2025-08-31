#include <bits/stdc++.h>
using namespace std;

constexpr const long long INF = 0x3f3f3f3f3f3f3f3f;
constexpr const int N = 403;
long long f[N][N][N];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, m;
	cin >> n >> m;
	memset(f, 0x3f, sizeof(f));
	for(int i = 1; i <= n; ++i)
		f[0][i][i] = 0;
	for(int u, v, w; m--; ) {
		cin >> u >> v >> w;
		f[0][u][v] = min(f[0][u][v], (long long)w);
	}
	for(int k = 1; k <= n; ++k)
		for(int i = 1; i <= n; ++i)
			for(int j = 1; j <= n; ++j) {
				f[k][i][j] = min(f[k][i][j], f[k - 1][i][j]);
				if(f[k - 1][i][k] != INF && f[k - 1][k][j] != INF)
					f[k][i][j] = min(f[k][i][j], f[k - 1][i][k] + f[k - 1][k][j]);
			}
	long long ans = 0;
	for(int k = 1; k <= n; ++k)
		for(int i = 1; i <= n; ++i)
			for(int j = 1; j <= n; ++j)
				if(f[k][i][j] != INF)
					ans += f[k][i][j];
	cout << ans << endl;
	return 0;
}
