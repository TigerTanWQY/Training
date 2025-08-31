#include <iostream>
#include <algorithm>
using namespace std;

constexpr const int N = 5003;
int a[N], c[N];
long long f[N][N];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, m;
	cin >> n >> m;
	for(int i = 1; i <= n; ++i)
		cin >> a[i];
	for(int x, w; m--; ) {
		cin >> x >> w;
		c[x] = w;
	}
	for(int i = 1; i <= n; ++i) {
		for(int j = 1; j <= i; ++j)
			f[i][j] = f[i - 1][j - 1] + a[i] + c[j];
		for(int j = 0; j < i; ++j)
			f[i][0] = max(f[i][0], f[i - 1][j]);
	}
	long long ans = 0;
	for(int i = 0; i <= n; ++i)
		ans = max(ans, f[n][i]);
	cout << ans << endl;
	return 0;
}