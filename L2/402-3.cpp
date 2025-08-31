#include <bits/stdc++.h>
using namespace std;

int n;

int calc(int x, int y) noexcept
{
	int z = n / x;
	if(n % x != 0)
		++z;
	return y * z;
}

int main()
{
	scanf("%d", &n);
	int ans = 100000000;
	for(int i = 1; i <= 3; ++i)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		ans = min(ans, calc(a, b));
	}
	printf("%d", ans);
	return 0;
}