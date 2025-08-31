#include <cstdio>
using namespace std;

int main()
{
	int a, b, c, d, e, ans = 0;
	scanf("%d%d%d%d%d", &a, &b, &c, &d, &e);
	ans += a % 3;
	a /= 3;
	b += a;
	e += a;
	ans += b % 3;
	b /= 3;
	c += b;
	a += b;
	ans += c % 3;
	c /= 3;
	d += c;
	b += c;
	ans += d % 3;
	d /= 3;
	e += d;
	c += d;
	ans += e % 3;
	e /= 3;
	a += e;
	d += e;
	printf("%d %d %d %d %d\n%d", a, b, c, d, e, ans);
	return 0;
}