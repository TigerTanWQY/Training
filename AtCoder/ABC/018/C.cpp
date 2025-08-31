#include <bits/stdc++.h>
using namespace std;

constexpr const int N = 1003;
bool a[N][N], b[N][N], vis[N][N];
int s[N][N];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, m, d;
	cin >> n >> m >> d;
	--d; int maxn = max(n, m), k = (maxn << 1) - 1;
	for(int i = 1; i <= maxn; ++i)
		for(int j = 1; j <= maxn; ++j)
			a[i][j] = true;
	for(int i = 1; i <= k; ++i)
		for(int j = 1; j <= k; ++j)
			b[i][j] = true;
	for(int i = 1; i <= n; ++i)
		for(int j = 1; j <= m; ++j) {
			char ch;
			cin >> ch;
			a[i][j] = (ch == 'x');
		}
	for(int i = 1; i <= maxn; ++i)
		for(int j = 1; j <= maxn; ++j) {
			b[i + j - 1][n - i + j] = a[i][j];
			vis[i + j - 1][n - i + j] = true;
		}
	for(int i = 1; i <= k; ++i)
		for(int j = 1; j <= k; ++j)
			b[i][j] &= !(vis[i - 1][j] && vis[i][j - 1] && vis[i + 1][j] && vis[i][j + 1]);
	for(int i = 1; i <= k; ++i)
		for(int j = 1; j <= k; ++j)
			s[i][j] = s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1] + b[i][j];
	int ans = 0;
	for(int i = d; i <= k - d; ++i)
		for(int j = d; j <= k - d; ++j)
			ans += (vis[i][j] && !(s[i + d][j + d] - s[i - d - 1][j + d] - s[i + d][j - d - 1] + s[i - d - 1][j - d - 1]));
	cout << ans << endl;
	return 0;
}
