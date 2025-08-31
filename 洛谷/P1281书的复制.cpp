#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

const int N = 503;
int a[N], x[N], y[N], n, m;

inline bool check(const int &z)
{
	int k = 1, tot = 0;
	for(int i = n; i >= 1; --i)
	{
		if(tot + a[i] > z)
		{
			tot = 0;
			++k;
		}
		tot += a[i];
	}
	return k > m;
}

int main()
{
	int L = 0, R = 0, tot = 0, k = 1;
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; ++i)
	{
		scanf("%d", &a[i]);
		R += a[i];
		L = max(L, a[i]);
	}
	while(L + 1 < R)
	{
		int M = (L + R) >> 1;
		if(check(M))
			L = M;
		else
			R = M;
	}
	y[1] = n;
	for(int i = n; i >= 1; --i)
	{
		if(tot + a[i] > R)
		{
			tot = 0;
			x[k] = i + 1;
			y[++k] = i;
		}
		tot += a[i];
	}
	x[k] = 1;
	for(int i = m; i >= 1; --i)
		printf("%d %d\n", x[i], y[i]);
	return 0;
}