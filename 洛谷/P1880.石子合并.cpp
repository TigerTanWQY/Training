#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

constexpr const int N = 103 * 2;
int a[N], f[2][N][N];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	cin >> n;
	for(int i = 1; i <= n; ++i) {
		cin >> a[i];
		a[i + n] = a[i];
	}
	memset(f[0], 0x3f, sizeof(f[0]));
	f[0][0][0] = 0;
	for(int i = 1; i <= 2 * n; ++i) {
		f[0][i][i] = 0;
		a[i] += a[i - 1];
	}
	for(int len = 1; len <= 2 * n; ++len)
		for(int L = 1; L <= 2 * n - len + 1; ++L) {
			int R = L + len - 1;
			for(int k = L; k < R; ++k)
				f[0][L][R] = min(f[0][L][R], f[0][L][k] + f[0][k + 1][R] + a[R] - a[L - 1]);
		}
	for(int len = 1; len <= 2 * n; ++len)
		for(int L = 1; L <= 2 * n - len + 1; ++L) {
			int R = L + len - 1;
			for(int k = L; k < R; ++k)
				f[1][L][R] = max(f[1][L][R], f[1][L][k] + f[1][k + 1][R] + a[R] - a[L - 1]);
		}
	int ans1 = 0x3f3f3f3f, ans2 = 0;
	for(int i = 1; i <= n; ++i) {
		ans1 = min(f[0][i][n + i - 1], ans1);
		ans2 = max(f[1][i][n + i - 1], ans2);
	}
	cout << ans1 << '\n' << ans2 << endl;
	return 0;
}