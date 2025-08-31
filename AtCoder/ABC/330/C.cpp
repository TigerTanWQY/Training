#include <cstdio>
#include <cmath>
#include <climits>
#include <algorithm>
using namespace std;
using LL = long long;

double MySqrt(const double &n)
{
	double x = 1.0, p = 1e-2;
	while(fabs(x * x - n) > p)
		x = (x + n / x) / 2.0;
	return x;
}

int main()
{
	LL d, ans = LLONG_MAX;
	scanf("%lld", &d);
	for(LL x = 0; (x - 1) * (x - 1) <= d; ++x)
	{
		LL y1 = MySqrt(abs(d - x * x)), y2 = ceil(MySqrt(abs(d - x * x)));
		ans = min({ans, abs(x * x + y1 * y1 - d), abs(x * x + y2 * y2 - d)});
	}
	printf("%lld", ans);
	return 0;
}