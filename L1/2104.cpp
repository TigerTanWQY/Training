#include <bits/stdc++.h>
using namespace std;

int a[1003][1003];

void func(int n, int m)
{
	for(int i = 1; i <= n; ++i)
	{
		for(int j = 1; j <= m; ++j)
			printf("%d ", a[i][j]);
		printf("\n");
	}
}

int main()
{
	int n, m;
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; ++i)
		for(int j = 1; j <= m; ++j)
			scanf("%d", a[i] + j);
	func(n, m);
	return 0;
}