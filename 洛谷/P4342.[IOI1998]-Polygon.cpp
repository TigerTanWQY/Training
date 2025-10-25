#include <bits/stdc++.h>
using namespace std;

char s[105];
int a[105], f[150][150], g[150][150];

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int n;
	cin >> n;
	for(int i = 1; i <= n; ++i) {
		cin >> s[i] >> a[i];
		a[n+i] = a[i];
		s[n+i] = s[i];
	}
	for(int i = 1; i <= n<<1; ++i)
		for(int j = 1; j <= n<<1; ++j)
		{ f[i][j] = -0x3f3f3f3f; g[i][j] = 0x3f3f3f3f; }
	for(int i = 1; i <= n<<1; ++i)
		f[i][i] = g[i][i] = a[i];
	for(int len = 2; len <= n; ++len)
		for(int i = 1, j = len; j <= n<<1; ++i, ++j)
			for(int k = i; k < j; ++k)
				if(s[k+1] == 'x') {
					f[i][j] = max({f[i][j], f[i][k] * f[k+1][j], g[i][k] * g[k+1][j],
									f[i][k] * g[k+1][j], g[i][k] * f[k+1][j]});
					g[i][j] = min({g[i][j], f[i][k] * f[k+1][j], g[i][k] * g[k+1][j],
									f[i][k] * g[k+1][j], g[i][k] * f[k+1][j]});
				} else if(s[k+1] == 't') {
					f[i][j] = max(f[i][j], f[i][k] + f[k+1][j]);
					g[i][j] = min(g[i][j], g[i][k] + g[k+1][j]);
				}
	int ans = -0x3f3f3f3f;
	for(int i = 1; i <= n; ++i)
		ans = max(ans, f[i][i+n-1]);
	cout << ans << '\n';
	for(int i = 1; i <= n; ++i)
		if(f[i][i+n-1] == ans)
			cout << i << ' ';
	cout << endl; return 0;
}
