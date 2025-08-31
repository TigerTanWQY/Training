#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

constexpr const int N = 103;
int a[N];
long long f[N][N][N];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, m, d;
	cin >> n >> m >> d;
	for(int i = 0; i < n; ++i)
		cin >> a[i];
	memset(f, -1, sizeof(f));
	f[0][0][0] = 0;
	for(int i = 0; i < n; ++i)
		for(int j = 0; j <= m; ++j)
			for(int k = 0; k < d; ++k) {
				if(!~f[i][j][k])
					continue;
				f[i + 1][j][k] = max(f[i + 1][j][k], f[i][j][k]);
				if(j != m)
					f[i + 1][j + 1][(k + a[i]) % d] = max(f[i + 1][j + 1][(k + a[i]) % d], f[i][j][k] + a[i]);
			}
	cout << f[n][m][0] << endl;
	return 0;
}