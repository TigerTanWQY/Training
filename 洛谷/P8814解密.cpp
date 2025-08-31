#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

int main()
{
	int k;
	scanf("%d", &k);
	while(k--)
	{
		long long n, d, e;
		scanf("%lld%lld%lld", &n, &d, &e);
		long long x = sqrt((n - e * d + 2) * (n - e * d + 2) - n * 4), y = n - e * d + 2, p = (x + y) / 2, q = y - p;
		(p * q == n && e * d == (p - 1) * (q - 1) + 1 && p && q)? printf("%lld %lld\n", min(p, q), max(p, q)): printf("NO\n");
	}
	return 0;
}