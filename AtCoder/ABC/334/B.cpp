#include <cstdio>
#include <algorithm>
using namespace std;
using LL = long long;

int m;
LL a, L, R;

LL func(const LL &x, const bool &f)
{
	if(f)
	{
		for(int i = 0; i < m; ++i)
			if((x - a + i) % m == 0)
				return x + i;
	}
	else
		for(int i = 0; i < m; ++i)
			if((x - a - i) % m == 0)
				return x - i;
	return -1;
}

int main()
{
	scanf("%lld%d%lld%lld", &a, &m, &L, &R);
	if(L == R)
	{
		if((L - a) % m)
			putchar('0');
		else
			putchar('1');
		return 0;
	}
	LL ans = func(R, true) - func(L, false);
	if((L - a) % m == 0 && (R - a) % m == 0)
		printf("%lld", ans / m + 1);
	else if((L - a) % m == 0 || (R - a) % m == 0)
		printf("%lld", ans / m);
	else
		printf("%lld", ans / m - 1);
	return 0;
}
