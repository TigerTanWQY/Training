#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
using LL = long long;

const int N = 1003;
int a[N][N];
LL f[N][N][2];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m;
	cin >> n >> m;
	for(int i = 1; i <= n; ++i)
		for(int j = 1; j <= m; ++j)
			cin >> a[j][i];
	swap(n, m);
	memset(f, -0x3f, sizeof(f));
	f[1][1][0] = f[1][1][1] = a[1][1];
	for(int i = 1; i <= n; ++i) {
		for(int j = 1; j <= m; ++j) {
			if(i != 1) {
				f[i][j][0] = max(f[i][j][0], max(f[i - 1][j][0], f[i - 1][j][1]) + a[i][j]);
				f[i][j][1] = max(f[i][j][1], max(f[i - 1][j][0], f[i - 1][j][1]) + a[i][j]);
			} if(j != 1)
				f[i][j][0] = max(f[i][j][0], f[i][j - 1][0] + a[i][j]);
		} for(int j = m; j; --j)
			if(j != m)
				f[i][j][1] = max(f[i][j][1], f[i][j + 1][1] + a[i][j]);
	}
	cout << max(f[n][m][0], f[n][m][1]);
	return 0;
}