#include <iostream>
#include <cstring>
using namespace std;
using LL = long long;

constexpr const int N = 10'003, M = 103;
int a[N];
LL f[N][M], g[N][M];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, m;
	cin >> n >> m;
	for(int i = 1; i <= n; ++i)
		cin >> a[i];
	memset(g, 0x3f, sizeof(g));
	memset(f, 0x3f, sizeof(f));
	LL ans = 0x3f3f3f3f3f3f3f3f;
	for(int i = 1; i <= m; ++i)
		for(int j = 1; j < i; ++j) {
			f[i][j] = a[i] + a[i - j];
			g[i][j] = min(g[i][j - 1], f[i][j]);
			if(n - i + j < m)
				ans = min(ans, f[i][j]);
		}
	for(int i = m + 1; i <= n; ++i)
		for(int j = 1; j < m; ++j) {
			f[i][j] = g[i - j][m - j] + a[i];
			g[i][j] = min(g[i][j - 1], f[i][j]);
			if(n - i + j < m)
				ans = min(ans, f[i][j]);
		}
	cout << ans << endl;
	return 0;
}