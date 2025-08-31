#include <bits/stdc++.h>
using namespace std;

long long c[100003];

int main()
{
	int n, m, p1;
	long long s1, s2;
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i)
		scanf("%lld", &c[i]);
	scanf("%d%d%lld%lld", &m, &p1, &s1, &s2);
	c[p1] += s1;
	long long sum1 = 0, sum2 = 0;
	for(int i = 1; i <= n; ++i)
		if(i < m)
			sum1 += c[i] * (m - i);
		else if(i > m)
			sum2 += c[i] * (i - m);
	long long ans = -1;
	int ansp2 = -1;
	for(int p2 = 1; p2 <= n; ++p2)
	{
		long long t1 = sum1, t2 = sum2;
		if(p2 < m)
			t1 += s2 * (m - p2);
		else
			t2 += s2 * (p2 - m);
		long long tmp = abs(t1 - t2);
		if(ansp2 == -1 || tmp < ans)
		{
			ans = tmp;
			ansp2 = p2;
		}
	}
	printf("%d", ansp2);
	return 0;
}