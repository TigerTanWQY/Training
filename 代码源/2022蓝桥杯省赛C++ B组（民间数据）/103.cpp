#include <cstdio>
using namespace std;

int main()
{
	long long a, b, n;
	scanf("%lld%lld%lld", &a, &b, &n);
	long long k = 5 * a + 2 * b, ans = n / k * 7;
	n %= k;
	if(n <= 5 * a)
		ans += n / a + (n % a != 0);
	else
	{
		n -= 5 * a;
		ans += 6 + (n > b);
	}
	printf("%lld", ans);
	return 0;
}