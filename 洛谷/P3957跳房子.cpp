#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
using LL = long long;

struct Data
{ LL x, s; }
a[500003];
LL dp[500003], n, d, k;

inline bool check(const int &g)
{
	LL L = max(1LL, d - g), R = d + g;
	memset(dp, 128, sizeof(dp));
	dp[0] = 0;
	for(int i = 1; i <= n; ++i)
		for(int j = i - 1; j >= 0; --j)
		{
			if(a[i].x - a[j].x < L)
				continue;
			if(a[i].x - a[j].x > R)
				break;
			dp[i] = max(dp[i], dp[j] + a[i].s);
			if(dp[i] >= k)
				return true;
		}
	return false;
}

int main()
{
	scanf("%lld%lld%lld", &n, &d, &k);
	for(int i = 1; i <= n; ++i)
		scanf("%lld%lld", &a[i].x, &a[i].s);
	int ans = -1;
	for(int L = 0, R = 1005, M = (L + R) >> 1; L <= R; M = (L + R) >> 1)
		if(check(M))
		{
			ans = M;
			R = M - 1;
		}
		else
			L = M + 1;
	printf("%d", ans);
	return 0;
}