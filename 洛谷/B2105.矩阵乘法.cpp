#include <bits/stdc++.h>
using namespace std;

constexpr const int N = 103;
int a[N][N], b[N][N], c[N][N];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, m, k;
	cin >> n >> m >> k;
	for(int i = 1; i <= n; ++i)
		for(int j = 1; j <= m; ++j)
			cin >> a[i][j];
	for(int i = 1; i <= m; ++i)
		for(int j = 1; j <= k; ++j)
			cin >> b[i][j];
	for(int i = 1; i <= n; ++i)
		for(int j = 1; j <= k; ++j)
			for(int l = 1; l <= m; ++l)
				c[i][j] += a[i][l] * b[l][j];
	for(int i = 1; i <= n; cout.put('\n'), ++i)
		for(int j = 1; j <= k; cout.put(' '), ++j)
			cout << c[i][j];
	cout.flush();
	return 0;
}
