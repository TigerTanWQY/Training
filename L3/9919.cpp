#include <bits/stdc++.h>
using namespace std;
using LL = long long;

const int N = 500003;
struct Data
{ LL x, s; }
a[N];
LL f[N], n, d, k;

bool check(const int &g)
{
	LL lpos = max(1LL, d - g), rpos = d + g;
	memset(f, 128, sizeof(f));
	f[0] = 0;
	for(int i = 1; i <= n; ++i)
	{
		for(int j = i - 1; j >= 0; --j)
		{
			if(a[i].x - a[j].x < lpos)
				continue;
			if(a[i].x - a[j].x > rpos)
				break;
			f[i] = max(f[i], f[j] + a[i].s);
			if(f[i] >= k)
				return true;
		}
	}
	return false;
}

int main()
{
	int ans = -1;
	scanf("%lld%lld%lld", &n, &d, &k);
	for(int i = 1; i <= n; ++i)
		scanf("%lld%lld", &a[i].x, &a[i].s); //x ÓÐÐò
	for(int l = 0, r = 1005, m = (l + r) >> 1; l <= r; m = (l + r) >> 1)
		if(check(m))
		{
			ans = m;
			r = m - 1;
		}
		else
			l = m + 1;
	printf("%d", ans);
	return 0;
}