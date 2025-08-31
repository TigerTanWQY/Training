#include <bits/stdc++.h>
using namespace std;

int a[100003];
long long s[100003];

int main()
{
	int n;
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i)
	{
		scanf("%d", &a[i]);
		s[i] = s[i - 1] + a[i];
	}
	long long ans = -10000000000, x = 0;
	for(int i = 1; i <= n; ++i)
	{
		ans = max(ans, s[i] - x);
		x = min(x, s[i]);
	}
	printf("%lld", ans);
	return 0;
}