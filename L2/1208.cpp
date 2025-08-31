#include <bits/stdc++.h>
using namespace std;

int calc(int x, const int &y)
{
	int ret = 0;
	while(x > 0)
	{
		if(x % 10 == y)
			++ret;
		x /= 10;
	}
	return ret;
}

int main()
{
	int n, x;
	scanf("%d%d", &n, &x);
	int ans = 0;
	for(int i = 1; i <= n; ++i)
		ans += calc(i, x);
	printf("%d", ans);
	return 0;
}