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
		if(++a[x][y] > 1 || ++a[y][x] > 1)
		{
			printf("No");
			return 0;
		}
	}
	printf("Yes");
	return 0;
}