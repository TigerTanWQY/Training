#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
using LL = long long;

const int N = 103;
const int M = 10000;
int a[N], b[N];
LL sa[N], sb[N], dp[N][M + 3];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int T;
	cin >> T;
	for(int n; T--; ) {
		cin >> n;
		LL tot = 0, ans = 0x3f3f3f3f;
		for(int i = 1; i <= n; ++i) {
			cin >> a[i];
			tot += (2LL * n - 2) * a[i] * a[i];
			sa[i] = sa[i - 1] + a[i];
		}
		for(int i = 1; i <= n; ++i) {
			cin >> b[i];
			tot += (2LL * n - 2) * b[i] * b[i];
			sb[i] = sb[i - 1] + b[i];
		}
		memset(dp, 0x3f, sizeof(dp));
		dp[0][0] = 0;
		for(int i = 1; i <= n; ++i)
			for(int j = 1; j <= M; ++j) {
				if(j >= a[i] && sa[i] + sb[i] >= j + b[i])
					dp[i][j] = min(dp[i][j], dp[i - 1][j - a[i]] + 1LL * (j - a[i]) * a[i] + (sa[i] + sb[i] - j - b[i]) * b[i]);
				if(j >= b[i] && sa[i] + sb[i] >= j + a[i])
					dp[i][j] = min(dp[i][j], dp[i - 1][j - b[i]] + 1LL * (j - b[i]) * b[i] + (sa[i] + sb[i] - j - a[i]) * a[i]);
			}
		for(int i = 1; i <= M; ++i)
			ans = min(ans, dp[n][i]);
		cout << (ans * 4 + tot) / 2 << '\n';
	}
	return 0;
}