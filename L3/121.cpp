#include <bits/stdc++.h>
using namespace std;

int n = 6, m = 6, a[9][9], cnt = 0;
bool b1[9][9], b2[9][9], b3[9][9];

int calc(const int &x, const int &y)
{
	if(x <= 2)
		if(y <= 3)
			return 1;
		else
			return 2;
	if(x <= 4)
		if(y <= 3)
			return 3;
		else
			return 4;
	if(y <= 3)
		return 5;
	else
		return 6;
}

void dfs(const int &x, const int &y)
{
	if(cnt >= 500)
		return;
	if(x == n + 1)
	{
		for(int i = 1; i <= n; ++i)
		{
			for(int j = 1; j <= m; ++j)
				printf("%d ", a[i][j]);
			printf("\n");
		}
		++cnt;
		return;
	}
	int nx, ny;
	if(y == m)
	{
		nx = x + 1;
		ny = 1;
	}
	else
	{
		nx = x;
		ny = y + 1;
	}
	if(a[x][y])
		dfs(nx, ny);
	else
	{
		for(int i = 1; i <= 6; ++i)
			if(!b1[x][i] && !b2[y][i] && !b3[calc(x, y)][i])
			{
				a[x][y] = i;
				b1[x][i] = b2[y][i] = b3[calc(x, y)][i] = true;
				dfs(nx, ny);
				b1[x][i] = b2[y][i] = b3[calc(x, y)][i] = false;
				a[x][y] = 0;
			}
	}
}

int main()
{
	for(int i = 1; i <= n; ++i)
		for(int j = 1; j <= m; ++j)
		{
			scanf("%d", &a[i][j]);
			if(a[i][j])
				b1[i][a[i][j]] = b2[j][a[i][j]] = b3[calc(i, j)][a[i][j]] = true;
		}
	dfs(1, 1);
	return 0;
}