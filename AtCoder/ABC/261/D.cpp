#include <bits/stdc++.h>
using namespace std;
using LL = long long;

const int N = 5003;
LL x[N], b[N], dp[N][N];

int main()
{
	int n, m;
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; ++i)
		scanf("%lld", &x[i]);
	for(int i = 0; i < m; ++i)
	{
		LL c, y;
		scanf("%lld%lld", &c, &y);
		b[c] = y;
	}
	for(int i = 1; i <= n; ++i)
	{
		for(int j = 1; j <= i; ++j)
			dp[i][j] = dp[i - 1][j - 1] + x[i] + b[j];
		for(int j = 0; j < i; ++j)
			dp[i][0] = max(dp[i][0], dp[i - 1][j]);
	}
	LL ans = 0LL;
	for(int i = 0; i <= n; ++i)
		ans = max(ans, dp[n][i]);
	printf("%lld", ans);
	return 0;
}