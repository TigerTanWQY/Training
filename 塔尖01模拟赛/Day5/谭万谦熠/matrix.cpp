#include <bits/stdc++.h>
using namespace std;

constexpr const int N = 503;
int c[N];
unsigned long long f[N][N];

int main() {
	freopen("matrix.in", "r", stdin);
	freopen("matrix.out", "w", stdout);
	cin.tie(nullptr)->sync_with_stdio(false);
	int n;
	cin >> n;
	memset(f, 0x3f, sizeof(f));
	for(int i = 0; i <= n; ++i) {
		cin >> c[i];
		f[i][i] = 0;
	}
	for(int len = 2; len <= n; ++len)
		for(int i = 1; i <= n - len + 1; ++i) {
			int j = i + len - 1;
			for(int k = i; k < j; ++k)
				f[i][j] = min(f[i][j], f[i][k] + f[k + 1][j] + 1ULL * c[i - 1] * c[k] * c[j]);
		}
	cout << f[1][n] << endl;
	return 0;
}
