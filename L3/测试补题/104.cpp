#include <cstdio>
#include <cstring>
using namespace std;
using LL = long long;

const int N = 1003;
int n, m;
LL r[N], b[N], dp[N][N];

inline LL abs(const LL &x)
{
	if(x < 0)
		return -x;
	else
		return x;
}

inline LL min(const LL &x, const LL &y)
{
	if(x < y)
		return x;
	else
		return y;
}

int main()
{
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; ++i)
		scanf("%lld", &r[i]);
	for(int i = 1; i <= m; ++i)
		scanf("%lld", &b[i]);
	memset(dp, 0x3f, sizeof(dp));
	dp[1][1] = abs(r[1] - b[1]);
	for(int i = 1; i <= n; ++i)
		for(int j = 1; j <= m; ++j)
		{
			dp[i + 1][j] = min(dp[i + 1][j], dp[i][j] + abs(r[i + 1] - b[j]));
			dp[i][j + 1] = min(dp[i][j + 1], dp[i][j] + abs(r[i] - b[j + 1]));
			dp[i + 1][j + 1] = min(dp[i + 1][j + 1], dp[i][j] + abs(r[i + 1] - b[j + 1]));
		}
	printf("%lld", dp[n][m]);
	return 0;
}