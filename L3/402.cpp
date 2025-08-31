#include <bits/stdc++.h>
using namespace std;

int a[1003][1003];

int main()
{
	int n, m;
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= m; ++i)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		++a[x][y];
		++a[y][x];
	}
	for(int i = 1; i <= n; ++i)
	{
		int ans = 0;
		for(int j = 1; j <= n; ++j)
			ans += a[i][j];
		printf("%d ", ans);
	}
	return 0;
}