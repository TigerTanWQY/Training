#include <bits/stdc++.h>
using namespace std;

int a[100003];
long long s[100003];
int n;

int calc1(int x)
{
	int L = 0, R = n + 1;
	while(L + 1 < R)
	{
		int M = (L + R) >> 1;
		if(a[M] < x)
			L = M;
		else
			R = M;
	}
	return L;
}

int calc2(int x)
{
	int L = 0, R = n + 1;
	while(L + 1 < R)
	{
		int M = (L + R) >> 1;
		if(a[M] <= x)
			L = M;
		else
			R = M;
	}
	return L;
}

int main()
{
	int m;
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; ++i)
		scanf("%d", &a[i]);
	sort(a + 1, a + n + 1);
	for(int i = 1; i <= n; ++i)
		s[i] = s[i - 1] + a[i];
	while(m--)
	{
		int l, r;
		scanf("%d%d", &l, &r);
		int x = calc1(l), y = calc2(r);
		printf("%d %lld\n", y - x, s[y] - s[x]);
	}
	return 0;
}