#include <bits/stdc++.h>
using namespace std;

long long a[13]{1};

int main()
{
	int k, n;
	scanf("%d%d", &k, &n);
	for(int i = 1; i <= 10; ++i)
		a[i] = a[i - 1] * k;
	long long ans = 0;
	for(int i = 0; i <= 10; ++i)
		if(n & (1 << i))
			ans += a[i];
	printf("%lld", ans);
	return 0;
}