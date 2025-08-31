#include <cstdio>
using namespace std;
using LL = long long;

int a[100003], n, k;

inline bool check(const LL &x)
{
	LL tot = 0;
	for(int i = 1; i <= n; ++i)
		tot += a[i] / x;
	return tot >= k;
}

int main()
{
	scanf("%d%d", &n, &k);
	for(int i = 1; i <= n; ++i)
		scanf("%d", &a[i]);
	LL L = 0, R = 1e13 + 1;
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