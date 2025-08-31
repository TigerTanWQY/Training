#include <cstdio>
#include <algorithm>
using namespace std;
using LL = long long;

int a[1000003], n, m;

inline bool check(const LL &x)
{
	LL tot = 0;
	for(int i = 1; i <= n; ++i)
		if(a[i] > x)
			tot += a[i] - x;
	return tot >= m;
}

int main()
{
	scanf("%d%d", &n, &m);
	int maxx = 0;
	for(int i = 1; i <= n; ++i)
	{
		scanf("%d", &a[i]);
		maxx = max(maxx, a[i]);
	}
	LL L = 0, R = maxx + 1;
	while(L + 1 < R)
	{
		LL M = (L + R) >> 1;
		if(check(M))
			L = M;
		else
			R = M;
	}
	printf("%lld", L);
	return 0;
}