#include <iostream>
#include <cmath>
#include <bitset>
#include <algorithm>
using namespace std;

constexpr const int V = 80, N = V + 3, V_MAX = 12'800;
bitset<V_MAX * 2 + 3> f[N][N];
int a[N][N];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, m;
	cin >> n >> m;
	for(int i = 1; i <= n; ++i)
		for(int j = 1; j <= m; ++j)
			cin >> a[i][j];
	for(int i = 1, x; i <= n; ++i)
		for(int j = 1; j <= m; ++j) {
			cin >> x;
			a[i][j] = abs(a[i][j] - x);
		}
	f[1][1][a[1][1] + V_MAX] = f[1][1][-a[1][1] + V_MAX] = true;
	for(int i = 1; i <= n; ++i)
		for(int j = 1; j <= m; ++j)
			f[i][j] |= (f[i - 1][j] << a[i][j]) | (f[i - 1][j] >> a[i][j]) | (f[i][j - 1] << a[i][j]) | (f[i][j - 1] >> a[i][j]);
	int ans = 0x3f3f3f3f;
	for(int i = 0; i <= V_MAX * 2; ++i)
		if(f[n][m][i])
			ans = min(ans, abs(i - V_MAX));
	cout << ans;
	cout.flush();
	return 0;
}