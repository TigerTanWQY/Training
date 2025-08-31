#include <bits/stdc++.h>
using namespace std;

int calc(const int &x, const int &y, const int &n)
{
	if(x == 1)
		return y;
	if(y == n)
		return x + n - 1;
	if(x == n)
		return -y + 3 * n - 1;
	if(y == 1)
		return -x + 4 * n - 2;
	return 0;
}

int main()
{
	int n, x, y, ans = 0;
	scanf("%d%d%d", &n, &x, &y);
	while(1 < x && x < n && 1 < y && y < n)
	{
		ans += 4 * (n - 1);
		n -= 2;
		--x;
		--y;
	}
	ans += calc(x, y, n);
	printf("%d", ans);
	return 0;
}