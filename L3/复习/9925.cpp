#include <iostream>
#include <algorithm>
using namespace std;

constexpr const int N = 1e3 + 3;
int a[N][N];
long long f[N][N], down[N][N], up[N][N];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, m;
	cin >> n >> m;
	for(int i = 1; i <= n; ++i)
		for(int j = 1; j <= m; ++j)
			cin >> a[i][j];
	for(int j = 1; j <= m; ++j) {
		for(int i = 1; i <= n; ++i)
			if(i == 1 && j == 1)
				up[i][j] = a[i][j];
			else if(i == 1)
				up[i][j] = f[i][j - 1] + a[i][j];
			else if(j == 1)
				up[i][j] = up[i - 1][j] + a[i][j];
			else
				up[i][j] = max(f[i][j - 1], up[i - 1][j]) + a[i][j];
		for(int i = n; i; --i)
			if(j == 1)
				down[i][j] = -0x3f3f3f3f3f3f3f3f;
			else if(i == n)
				down[i][j] = f[i][j - 1] + a[i][j];
			else
				down[i][j] = max(f[i][j - 1], down[i + 1][j]) + a[i][j];
		for(int i = 1; i <= n; ++i)
			f[i][j] = max(up[i][j], down[i][j]);
	}
	cout << f[n][m] << endl;
	return 0;
}