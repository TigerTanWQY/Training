#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 1000003;
ll a[N], s[N], b[N]{LLONG_MIN};
__int128 c[N];

int main()
{
	int n, p;
	scanf("%d%d", &n, &p);
	for(int i = 1; i <= n; ++i)
	{
		scanf("%lld", &a[i]);
		s[i] = s[i - 1] + a[i];
	}
	ll x = 0;
	for(int i = 1; i <= n; ++i)
	{
		b[i] = max(b[i - 1], s[i] - x);
		x = min(x, s[i]);
	}
	c[1] = b[1];
	c[2] = b[1] + c[1];
	for(int i = 3; i <= n; ++i)
		c[i] = c[i - 1] + max(0LL, b[i - 1]);
	__int128 ans = c[1];
	for(int i = 2; i <= n; ++i)
		ans = max(ans, c[i]);
	printf("%d", (int) (ans % p));
	return 0;
}