#include <bits/stdc++.h>
using namespace std;

const int MOD = 998244353;
const int N = 103;
int a[N], dp[N][N][N];

int main()
{
	int n, ans = 0;
	scanf("%d", &n);
	for(int i = 0; i < n; ++i)
		scanf("%d", &a[i]);
	for(int i = 1; i <= n; ++i)
	{
		memset(dp, 0, sizeof(dp));
		dp[0][0][0] = 1;
		for(int j = 0; j < n; ++j)
		{
			for(int k = 0; k <= i; ++k)
				for(int l = 0; l < i; ++l)
				{
					dp[j + 1][k][l] = (dp[j + 1][k][l] + dp[j][k][l]) % MOD;
					if(k != i)
						dp[j + 1][k + 1][(l + a[j]) % i] = (dp[j][k][l] + dp[j + 1][k + 1][(l + a[j]) % i]) % MOD;
				}
			ans = (ans + dp[n][i][0]) % MOD;
		}
	}
	printf("%d", ans);
	return 0;
}