#include <iostream>
#include <algorithm>
using namespace std;

const int N = 203;
int a[N], f[N][N];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	cin >> n;
	for(int i = 1; i <= n; ++i) {
		cin >> a[i];
		a[i + n] = a[i];
	}
	for(int L = 1; L <= 2 * n; ++L) {
		a[L] += a[L - 1];
		for(int R = 1; R <= 2 * n; ++R)
			f[L][R] = 0x3f3f3f3f;
		f[L][L] = 0;
	}
	for(int len = 1; len <= 2 * n; ++len)
		for(int L = 1; L + len - 1 <= 2 * n; ++L) {
			int R = L + len - 1;
			for(int k = L; k < R; ++k)
				f[L][R] = min(f[L][R], f[L][k] + f[k + 1][R] + a[R] - a[L - 1]);
		}
	int ans = 0x3f3f3f3f;
	for(int L = 1; L <= n; ++L)
		ans = min(f[L][n + L - 1], ans);
	cout << ans;
	cout.flush();
	return 0;
}