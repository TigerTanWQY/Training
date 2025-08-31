#include <iostream>
#include <algorithm>
using namespace std;

constexpr const int N = 2e5 + 3, LOGN = 18 + 3;
int n, k, a[N], f[LOGN][N], g[LOGN][N];

int check(const int x) {
	for(int L = 1, R = 1, tot = 0; L <= n; ++L) {
		while(tot < x) {
			tot += a[R];
			R = R % n + 1;
		}
		f[0][L] = R; g[0][L] = (R + n - L) % n;
		tot -= a[L];
	}
	for(int i = 1; i <= 18; ++i)
		for(int j = 1; j <= n; ++j) {
			f[i][j] = f[i - 1][f[i - 1][j]];
			g[i][j] = min(0x3f3f3f3f, g[i - 1][j] + g[i - 1][f[i - 1][j]]);
		}
	int res = 0;
	for(int i = 1; i <= n; ++i) {
		int u = i, cnt = 0;
		for(int j = 0; j <= 18; ++j)
			if(k >> j & 1) {
				cnt += g[j][u];
				if(cnt > n)
					break;
				u = f[j][u];
			}
		if(cnt <= n)
			++res;
	}
	return res;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n >> k;
	int tot = 0;
	for(int i = 1; i <= n; ++i) {
		cin >> a[i];
		tot += a[i];
	}
	int L = 0, R = tot / k, ans = 0;
	while(L <= R) {
		const int M = (L + R) / 2;
		if(check(M)) {
			L = M + 1;
			ans = M;
		}
		else
			R = M - 1;
	}
	cout << ans << ' ' << n - check(ans) << endl;
	return 0;
}