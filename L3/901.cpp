#include <bits/stdc++.h>
using namespace std;

int a[100003], c[100003];

long long msort(const int &l, const int &r)
{
	if(l == r)
		return 0LL;
	int m = (l + r) / 2;
	long long ret = msort(l, m) + msort(m + 1, r);
	int p1 = l, p2 = m + 1, tot = 0;
	while(p1 <= m && p2 <= r)
		if(a[p1] < a[p2])
		{
			c[++tot] = a[p1++];
			ret += p2 - m - 1;
		}
		else
			c[++tot] = a[p2++];
	while(p1 <= m)
	{
		c[++tot] = a[p1++];
		ret += p2 - m - 1;
	}
	while(p2 <= r)
		c[++tot] = a[p2++];
	for(int i = 1; i <= tot; ++i)
		a[i + l - 1] = c[i];
	return ret;
}

int main()
{
	int n;
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i)
		scanf("%d", &a[i]);
	printf("%lld", msort(1, n));
	return 0;
}