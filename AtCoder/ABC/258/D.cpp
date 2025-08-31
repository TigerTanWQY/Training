#include <bits/stdc++.h>
using namespace std;

const int N = 200003;
int a[N], b[N];

int main()
{
	int n, x;
	scanf("%d%d", &n, &x);
	for(int i = 0; i < n; ++i)
		scanf("%d%d", &a[i], &b[i]);
	long long ans = LLONG_MAX, tot = 0;
	for(int i = 0; i < n; ++i)
	{
		if(i + 1 > x)
			break;
		tot += a[i] + b[i];
		ans = min(ans, tot + 1LL * b[i] * (x - i - 1));
	}
	printf("%lld", ans);
	return 0;
}