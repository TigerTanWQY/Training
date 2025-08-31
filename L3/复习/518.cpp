#include <iostream>
using namespace std;

constexpr const int N = 103;
int a[N], f[N][N];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, m;
	cin >> n >> m;
	for(int i = 1; i <= n; ++i)
		cin >> a[i];
	f[0][0] = 1;
	for(int i = 1; i <= n; ++i)
		for(int j = 0; j <= m; ++j)
			for(int k = 0; k <= a[i]; ++k)
				if(j >= k) {
					f[i][j] += f[i - 1][j - k];
					f[i][j] %= 1000007;
				}
	cout << f[n][m] << endl;
	return 0;
}