#include <bits/stdc++.h>
using namespace std;

int a[103][103];

int main()
{
	int n, m;
	scanf("%d%d", &n, &m);
	int i = 1, j = m, x = 1;
	a[1][m] = 1;
	while(x < n * m)
	{
		while(a[i][j - 1] == 0 && j - 1 >= 1)
			a[i][--j] = ++x;
		while(a[i + 1][j] == 0 && i + 1 <= n)
			a[++i][j] = ++x;
		while(a[i][j + 1] == 0 && j + 1 <= m)
			a[i][++j] = ++x;
		while(a[i - 1][j] == 0 && i - 1 >= 1)
			a[--i][j] = ++x;
	}
	for(i = 1; i <= n; ++i)
	{
		for(j = 1; j <= m; ++j)
			printf("%d ", a[i][j]);
		printf("\n");
	}
	return 0;
}