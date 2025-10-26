#include <bits/stdc++.h>
using namespace std;

constexpr const int N = 203;
int a[N];
long long f[N][N];

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int n;
	cin >> n;
	for(int i = 1; i <= n; ++i) {
		cin >> a[i];
		a[i+n] = a[i];
	}
	for(int len = 3; len <= 2 * n; ++len)
		for(int i = 1; i+len-1 <= 2*n; ++i) {
			int j = i+len-1;
			for(int k = i+1; k <= j-1; ++k)
				f[i][j] = max(f[i][j], f[i][k] + f[k][j] + a[i] * a[k] * a[j]);
		}
	long long ans = 0;
	for(int i = 1; i <= n; ++i)
		ans = max(ans, f[i][i+n]);
	cout << ans << endl;
	return 0;
}
