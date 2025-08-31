#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n, p, a;
	scanf("%d%d%d", &n, &p, &a);
	long long su = max(a, 0), maxx = a, maxn = 2 * a;
	bool flag = a > 0;
	for(n -= 2; n; n--, su = max(su, 0LL))
	{
		int c;
		scanf("%d", &c);
		su += c;
		maxn += max(maxx = max(maxx, su), 0LL);
		if(flag)
			maxn %= p;
		else if(maxn > a)
			flag = true;
	}
	maxn = (flag? maxn: a);
	printf("%lld", maxn % p);
	return 0;
}