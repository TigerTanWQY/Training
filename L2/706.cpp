#include <bits/stdc++.h>
using namespace std;

int n, a[100003];
long long k;

long long calc(long long x)
{
	long long ans = 0;
	for(int i = 1; i <= n; ++i)
		if(a[i] < x)
			ans += x - a[i];
	return ans;
}

int main()
{
	scanf("%d%lld", &n, &k);
	for(int i = 1; i <= n; ++i)
		scanf("%d", &a[i]);
	long long L = 1, R = 10000100000001LL;
	while(L + 1 < R)
	{
		long long M = (L + R) >> 1;
		if(calc(M) <= k)
			L = M;
		else
			R = M;
	}
	printf("%lld", L);
	return 0;
}