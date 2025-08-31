#include <cstdio>
using namespace std;
using LL = long long;

const int MOD = 1e9 + 7;
LL a[100003];

LL gcd(const LL &x, const LL &y)
{ return y? gcd(y, x % y): x; }

int main()
{
	int n;
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i)
		scanf("%lld", &a[i]);
	for(bool flag; flag; )
	{
		flag = false;
		for(int i = 1; i < n; ++i)
			if(a[i] % a[i + 1] == 0 || a[i + 1] % a[i] == 0)
			{
				int x = gcd(a[i], a[i + 1]), y = a[i] * a[i + 1] / x;
				a[i] = x;
				a[i + 1] = y;
				flag = true;
			}
	}
	LL ans = 0;
	for(int i = 1; i <= n; ++i)
		ans = (ans + a[i]) % MOD;
	printf("%lld", ans);
	return 0;
}