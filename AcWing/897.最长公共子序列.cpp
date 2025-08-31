#include <iostream>
using namespace std;

const int N = 1003;
char a[N], b[N];
int f[N][N];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m;
	cin >> n >> m >> (a + 1) >> (b + 1);
	for(int i = 1; i <= n; ++i)
		for(int j = 1; j <= m; ++j) {
			f[i][j] = max(f[i][j - 1], f[i - 1][j]);
			if(a[i] == b[j])
				f[i][j] = max(f[i][j], f[i - 1][j - 1] + 1);
		}
	cout << f[n][m];
	return 0;
}