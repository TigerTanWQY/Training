#include <cstdio>
#include <algorithm>
using namespace std;
using LL = long long;

const int MOD = 998244353;

int main()
{
	LL n, ans = 0, x = 10;
	scanf("%lld", &n);
	for(int _ = 1; _ <= 18; ++_, x *= 10)
	{
		LL L = x / 10, R = min(n, x - 1);
		if(L <= R)
		{
			LL y = (R - L + 1) % MOD;
			ans = (ans + y * (y + 1) % MOD * (MOD / 2 + 1) % MOD) % MOD;
		}
	}
	printf("%lld", ans);
	return 0;
}