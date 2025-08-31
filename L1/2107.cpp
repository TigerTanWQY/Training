#include <bits/stdc++.h>
using namespace std;

int my_pow(int base, int exr)
{
	int ret = base;
	for(int i = 1; i < exr; ++i)
		ret *= base;
	return ret;
}

int main()
{
	int n, m;
	scanf("%d%d", &n, &m);
	int ans = 0;
	for(int i = 1; i <= n; ++i)
		ans += my_pow(i, m);
	printf("%d", ans);
	return 0;
}