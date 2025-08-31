#include <bits/stdc++.h>
using namespace std;

int a[200003];
int n;

int lb(int x)
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

int leb(int x)
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
	while(m--)
	{
		int x;
		scanf("%d", &x);
		int lx = lb(x), ex = leb(x) - lx, gx = n - lx - ex;
		printf("%d %d %d\n", lx, ex, gx);
	}
	return 0;
}