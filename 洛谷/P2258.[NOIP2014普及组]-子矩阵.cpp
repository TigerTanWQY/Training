#include <bits/stdc++.h>
using namespace std;

constexpr const int N = 16;
int a[N+3][N+3], dp[N+3][N+3][(1<<N) + 3];

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int n, m, r, c, ans = 0x3f3f3f3f;
	cin >> n >> m >> r >> c;
	for(int i = 1; i <= n; ++i)
		for(int j = 1; j <= m; ++j) {
			cin >> a[i][j];
			for(int k = 0; k < (1 << m); ++k)
				dp[i][j][k] = 0x3f3f3f3f;
		}
	for(int i = 1; i <= n; ++i) {
		for(int j = (1 << c) - 1; j < (1 << m); ++j) {
			int ti = 0, tcnt = 0, tem1 = 0;
			for(int ii = 0; (1 << ii) <= j; ++ii)
				if((1 << ii) & j)
					if(ti) {
						tem1 += abs(a[i][ii + 1] - a[i][ti]);
						ti = ii + 1;
						++tcnt;
					}
					else {
						ti = ii + 1;
						++tcnt;
					}
			if(tcnt != c)
				continue;
			for(int k = 1; k <= min(r, i); ++k)
				for(int kk = k - 1; kk < i; ++kk) {
					int tem2 = 0;
					if(kk)
						for(int iii = 0; (1 << iii) <= j; ++iii)
							if(1 << iii & j)
								tem2 += abs(a[i][iii + 1] - a[kk][iii + 1]);
					dp[i][k][j] = min(dp[i][k][j], dp[kk][k - 1][j] + tem1 + tem2);
				}
			ans = min(ans, dp[i][r][j]);
		}
	}
	cout << ans << endl;
	return 0;
}
