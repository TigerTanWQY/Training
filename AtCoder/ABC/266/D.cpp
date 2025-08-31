#include <iostream>
#include <algorithm>
using namespace std;
using LL = long long;

const LL INF = 0x3f3f3f3f3f3f3f3f;
const int N = 100000;
LL dp[5][N + 3], x[N + 3], a[N + 3];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin >> n;
	for(int t, i, j; n--; ) {
		cin >> t >> i >> j;
		x[t] = i;
		a[t] = j;
	}
	for(int i = 1; i < 5; ++i)
		dp[i][0] = -INF;
	for(int t = 1; t <= N; ++t) {
		for(int i = 0; i < 5; ++i) {
			dp[i][t] = dp[i][t - 1];
			if(i != 0)
				dp[i][t] = max(dp[i][t], dp[i - 1][t - 1]);
			if(i != 4)
				dp[i][t] = max(dp[i][t], dp[i + 1][t - 1]);
		}
		dp[x[t]][t] += a[t];
	}
	LL ans = 0;
	for(int i = 0; i < 5; ++i)
		ans = max(ans, dp[i][N]);
	cout << ans;
	return 0;
}
