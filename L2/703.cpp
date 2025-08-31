#include <bits/stdc++.h>
using namespace std;

int a[100003];
long long s[100003];
int n, l;

int calc(long long x)
{
	int L = l - 1, R = n + 1;
	while(L + 1 < R)
	{
		int M = (L + R) >> 1;
		if(s[M] - s[l - 1] <= x)
			L = M;
		else
			R = M;
	}
	if(L < l)
		L = -1;
	return L;
}

int main()
{
	int m;
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; ++i)
	{
		scanf("%d", &a[i]);
		s[i] = s[i - 1] + a[i];
	}
	while(m--)
	{
		long long x;
		scanf("%d%lld", &l, &x);
		printf("%d\n", calc(x));
	}
	return 0;
}