#include <bits/stdc++.h>
using namespace std;

constexpr const int N = 1e5 + 3;
int f[N][103][3], a[N];

int main () {
	cin.tie(nullptr)->sync_with_stdio(false);
	int n, k;
	cin >> n >> k;
	for(int i = 1; i <= n; ++i)
		cin >> a[i];
	memset(f, -0x3f, sizeof f);
	f[0][0][0] = 0;
	for(int i = 1; i <= n; ++i)
		for(int j = 0; j <= k; ++j) {
			f[i][j][0] = f[i-1][j][0];
			if(j)
				f[i][j][0] = max(f[i][j][0], f[i-1][j-1][1] + a[i]);
			f[i][j][1] = max(f[i-1][j][1], f[i-1][j][0] - a[i]);
		}
	int ans = 0;
	for(int i = 0; i <= k; ++i)
		ans = max(ans, f[n][i][0]);
	cout << ans << endl;
	return 0;
}
