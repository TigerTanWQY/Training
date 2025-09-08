#include <bits/stdc++.h>
using namespace std;

constexpr const int N = 2003, V = 303;
double f[N][N][2], g[V][V], k[N];
int c[N], d[N];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, m, e, v;
	cin >> n >> m >> v >> e;
	for(int i = 1; i <= n; ++i)
		cin >> c[i];
	for(int i = 1; i <= n; ++i)
		cin >> d[i];
	for(int i = 1; i <= n; ++i)
		cin >> k[i];
	for(int i = 1; i <= v; ++i) {
		for(int j = 1; j <= v; ++j)
			g[i][j] = 1e18;
		g[i][i] = 0;
	}
	for(int x, y, w; e--; ) {
		cin >> x >> y >> w;
		g[x][y] = g[y][x] = min(g[x][y], 1.0 * w);
	}
	for(int l = 1; l <= v; ++l)
		for(int i = 1; i <= v; ++i)
			for(int j = 1; j <= v; ++j)
				if(g[i][l] + g[l][j] < g[i][j])
					g[i][j] = g[i][l] + g[l][j];
	for(int i = 0; i <= n; ++i)
		for(int j = 0; j <= m; ++j)
			f[i][j][0] = f[i][j][1] = 1e18;
	f[1][1][1] = f[1][0][0] = 0;
	for(int i = 2; i <= n; ++i)
		for(int j = 0; j <= m; ++j) {
			f[i][j][0] = min(f[i - 1][j][0] + g[c[i - 1]][c[i]], f[i - 1][j][1] + k[i - 1] * g[d[i - 1]][c[i]] + (1 - k[i - 1]) * g[c[i - 1]][c[i]]);
			if(j > 0)
				f[i][j][1] = min(f[i - 1][j - 1][0] + g[c[i - 1]][d[i]] * k[i] + g[c[i - 1]][c[i]] * (1 - k[i]), f[i - 1][j - 1][1] + k[i - 1] * k[i] * g[d[i - 1]][d[i]] + k[i - 1] * (1 - k[i]) * g[d[i - 1]][c[i]] + (1 - k[i - 1]) * k[i] * g[c[i - 1]][d[i]] + (1 - k[i - 1]) * (1 - k[i]) * g[c[i - 1]][c[i]]);
		}
	double ans = 1e18;
	for(int i = 0; i <= m; ++i)
		ans = min({ans, f[n][i][1], f[n][i][0]});
	cout << fixed << setprecision(2) << ans << endl;
	return 0;
}
