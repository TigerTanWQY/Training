#include <bits/stdc++.h>
using namespace std;
using LL = long long;

int main()
{
	LL k, x, ans = 1;
	scanf("%lld", &k);
	for(LL p = 2; (p * p) <= k; ++p)
	{
		LL a = 0, n = 0;
		while(k % p == 0)
		{
			k /= p;
			++a;
		}
		while(a > 0)
		{
			n += p;
			x = n;
			while(x % p == 0)
			{
				x /= p;
				--a;
			}
		}
		ans = max(ans, n);
	}
	ans = max(ans, k);
	printf("%lld", ans);
	return 0;
}