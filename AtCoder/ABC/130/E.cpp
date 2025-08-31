#include <iostream>
using namespace std;

const int P = 1e9 + 7;
const int N = 2003;
int a[N], b[N], f[N][N];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m;
	cin >> n >> m;
	for(int i = 1; i <= n; ++i)
		cin >> a[i];
	for(int i = 1; i <= m; ++i)
		cin >> b[i];
	for(int i = 1; i <= n; ++i)
		for(int j = 1; j <= m; ++j) {
			f[i][j] = f[i - 1][j] + f[i][j - 1] - f[i - 1][j - 1];
			if(a[i] == b[j])
				f[i][j] += f[i - 1][j - 1] + 1;
			if(f[i][j] < 0)
				f[i][j] += P;
			if(f[i][j] >= P) // 优化，避免使用较慢的取模，而用减法代替。
				f[i][j] -= P;
		}
	cout << f[n][m] + 1;
	return 0;
}