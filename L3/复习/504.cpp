#include <iostream>
#include <algorithm>
using namespace std;

constexpr const int N = 1e3 + 3;
int a[N], b[N], f[N][N];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, m;
	cin >> n >> m;
	for(int i = 1; i <= n; ++i)
		cin >> a[i];
	for(int i = 1; i <= m; ++i)
		cin >> b[i];
	for(int i = 1; i <= n; ++i)
		for(int j = 1; j <= m; ++j) {
			f[i][j] = max(f[i - 1][j], f[i][j - 1]);
			if(a[i] == b[j])
				f[i][j] = max(f[i][j], f[i - 1][j - 1] + 1);
		}
	cout << f[n][m] << endl;
	return 0;
}