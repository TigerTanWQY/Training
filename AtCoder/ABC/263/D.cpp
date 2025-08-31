#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n, l, r;
	scanf("%d%d%d", &n, &l, &r);
	long long pre = 0, ans = 1LL * r * n;
	for(int i = 1; i <= n; ++i)
	{
		int a;
		scanf("%d", &a);
		pre = min(pre + a, 1LL * i * l);
		ans = min(ans, pre + 1LL * (n - i) * r);
	}
	printf("%lld", ans);
	return 0;
}