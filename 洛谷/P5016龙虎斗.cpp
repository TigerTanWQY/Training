#include <cstdio>
#include <cmath>
using namespace std;
using LL = long long;

LL c[100003];

int main()
{
	int n, m, p1, s1, s2, ansp2 = -1;
	LL totl = 0, toth = 0, ans = -1;
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i)
		scanf("%lld", &c[i]);
	scanf("%d%d%d%d", &m, &p1, &s1, &s2);
	c[p1] += s1;
	for(int i = 1; i <= n; ++i)
		if(i < m)
			totl += c[i] * (m - i);
		else if(i > m)
			toth += c[i] * (i - m);
	for(int p2 = 1; p2 <= n; ++p2)
	{
		LL t1 = totl, t2 = toth;
		if(p2 < m)
			t1 += 1LL * s2 * (m - p2);
		else
			t2 += 1LL * s2 * (p2 - m);
		LL tmp = abs(t1 - t2);
		if(ansp2 == -1 || tmp < ans)
		{
			ans = tmp;
			ansp2 = p2;
		}
	}
	printf("%d", ansp2);
	return 0;
}