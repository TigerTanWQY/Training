#include <bits/stdc++.h>
using namespace std;

constexpr const int N(103);
int a[N][N], f[N][N];

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	for(int i(1); i <= n; ++i)
		for(int j(1); j <= m; ++j)
			cin >> a[i][j];
	for(int i(1); i <= m; ++i)
		for(int j(1); j <= min(i, n); ++j)
			f[i][j] = (i > j? max(f[i - 1][j], f[i - 1][j - 1] + a[j][i]): f[i - 1][j - 1] + a[i][j]);
	cout << f[m][n] << endl;
	return 0;
}
