#include <bits/stdc++.h>
using namespace std;

constexpr const int N = 403;
int a[N], s[N], f[N][N], g[N][N];

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int n;
	cin >> n;
	for(int i = 1; i <= n; ++i) {
		cin >> a[i];
		a[i+n] = a[i];
	}
	memset(g, 0x3f, sizeof g);
	for(int i = 1; i <= 2*n; ++i) {
		s[i] = s[i-1] + a[i];
		f[i][i] = g[i][i] = 0;
	}
	for(int len = 2; len <= n; ++len)
		for(int i = 1; i+len-1 <= 2*n; ++i) {
			int j = i+len-1;
			for(int k = i; k < j; ++k) {
				f[i][j] = max(f[i][j], f[i][k] + f[k+1][j] + s[j] - s[i-1]);
				g[i][j] = min(g[i][j], g[i][k] + g[k+1][j] + s[j] - s[i-1]);
			}
		}
	int ans1 = 0, ans2 = 2e9;
	for(int i = 1; i <= n+1; ++i) {
		ans1 = max(ans1, f[i][i+n-1]);
		ans2 = min(ans2, g[i][i+n-1]);
	}
	cout << ans2 << '\n' << ans1 << endl;
	return 0;
}
