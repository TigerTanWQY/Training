#include <bits/stdc++.h>
using namespace std;

int a[1003][1003];
long long dp[1003][1003], down[1003][1003], up[1003][1003];

int main()
{
	int n, m;
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; ++i)
		for(int j = 1; j <= m; ++j)
			scanf("%d", &a[i][j]);
	for(int j = 1; j <= m; ++j)
	{
		for(int i = 1; i <= n; ++i)
		{
			if(i == 1 && j == 1)
				up[i][j] = a[i][j];
			else if(i == 1)
				up[i][j] = dp[i][j - 1] + a[i][j];
			else if(j == 1)
				up[i][j] = up[i - 1][j] + a[i][j];
			else
				up[i][j] = max(dp[i][j - 1], up[i - 1][j]) + a[i][j];
		}
		for(int i = n; i >= 1; --i)
		{
			if(j == 1)
				down[i][j] = LLONG_MIN;
			else if(i == n)
				down[i][j] = dp[i][j - 1] + a[i][j];
			else
				down[i][j] = max(dp[i][j - 1], down[i + 1][j]) + a[i][j];
		}
		for(int i = 1; i <= n; ++i)
			dp[i][j] = max(up[i][j], down[i][j]);
	}
	printf("%lld", dp[n][m]);
	return 0;
}