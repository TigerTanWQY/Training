#include <iostream>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;

constexpr const int N = 16 + 3;
int a[N][N], f[N][N], w[N], g[N][N], c[N], n, m, H, W, ans = 0x3f3f3f3f;

void dfs(const int x, const int y) {
	if(y > H) {
		memset(f, 0x3f, sizeof(f));
		memset(w, 0, sizeof(w));
		memset(g, 0, sizeof(g));
		for(int i = 1; i <= m; ++i)
			for(int j = 1; j < H; ++j)
				w[i] += abs(a[c[j]][i] - a[c[j + 1]][i]);
		for(int i = 1; i < m; ++i)
			for(int j = i + 1; j <= m; ++j)
				for(int k = 1; k <= H; ++k)
					g[i][j] += abs(a[c[k]][i] - a[c[k]][j]);
		f[0][0] = 0;
		for(int i = 1; i <= W; ++i)
			for(int j = i; j <= m; ++j)
				for(int k = 0; k < j; ++k)
					f[i][j] = min(f[i][j], f[i - 1][k] + w[j] + g[k][j]);
		for(int i = W; i <= m; ++i)
			ans = min(ans, f[W][i]);
		return;
	} else if(x > n)
		return;
	dfs(x + 1, y);
	c[y] = x;
	dfs(x + 1, y + 1);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n >> m >> H >> W;
	for(int i = 1; i <= n; ++i)
		for(int j = 1; j <= m; ++j)
			cin >> a[i][j];
	dfs(1, 1);
	cout << ans << endl;
	return 0;
}