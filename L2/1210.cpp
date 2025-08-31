#include <bits/stdc++.h>
using namespace std;

char a[103][103];

int main()
{
	int n, m;
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; ++i)
		scanf("%s", a[i] + 1);
	for(int i = 1; i <= n; ++i)
	{
		for(int j = 1; j <= m; ++j)
		{
			if(a[i][j] == '*')
			{
				printf("*");
				continue;
			}
			int ans = 0;
			for(int dx = -1; dx <= 1; ++dx)
				for(int dy = -1; dy <= 1; ++dy)
				{
					int x = i + dx, y = j + dy;
					if(a[x][y] == '*')
						++ans;
				}
			printf("%d", ans);
		}
		printf("\n");
	}
	return 0;
}