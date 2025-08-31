#include <cstdio>
using namespace std;

const int MOD = 998244353;
long long dp[1000003][2][2];

int main()
{
	int h, w, k, sx, sy, ex, ey;
	scanf("%d%d%d%d%d%d%d", &h, &w, &k, &sx, &sy, &ex, &ey);
	dp[0][sx != ex][sy != ey] = 1;
	for(int i = 1; i <= k; ++i)
	{
		dp[i][0][0] = (dp[i - 1][0][1] + dp[i - 1][1][0]) % MOD;
		dp[i][0][1] = (((w - 1) * dp[i - 1][0][0] % MOD + (w - 2) * dp[i - 1][0][1] % MOD) % MOD + dp[i - 1][1][1]) % MOD;
		dp[i][1][0] = (((h - 1) * dp[i - 1][0][0] % MOD + (h - 2) * dp[i - 1][1][0] % MOD) % MOD + dp[i - 1][1][1]) % MOD;
		dp[i][1][1] = (((h - 1) * dp[i - 1][0][1] % MOD + (w - 1) * dp[i - 1][1][0] % MOD) % MOD + (h + w - 4) * dp[i - 1][1][1] % MOD) % MOD;
	}
	printf("%lld", dp[k][0][0] % MOD);
	return 0;
}