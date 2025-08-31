#include <bits/stdc++.h>
using namespace std;

const int d[8][2]{{-1, -1}, {0, -1}, {1, -1}, {-1, 0}, {1, 0}, {-1, 1}, {0, 1}, {1, 1}};
int c[1000003][2], w[1003][1003], n, cnt = 0;
bool b[1003][1003];

void dfs(const int &x, const int &y)
{
	c[++cnt][0] = x;
	c[cnt][1] = y;
	b[x][y] = true;
	for(int i = 0; i < 8; ++i)
	{
		int tx = x + d[i][0], ty = y + d[i][1];
		if(1 > tx || tx > n || 1 > ty || ty > n)
			continue;
		if(w[tx][ty] == w[x][y] && !b[tx][ty])
			dfs(tx, ty);
	}
}

int main()
{
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i)
		for(int j = 1; j <= n; ++j)
			scanf("%d", &w[i][j]);
	int p = 0, v = 0;
	for(int i = 1; i <= n; ++i)
		for(int j = 1; j <= n; ++j)
			if(!b[i][j])
			{
				cnt = 0;
				dfs(i, j);
				bool ok = true;
				for(int k = 1; k <= cnt && ok; ++k)
				{
					int x = c[k][0], y = c[k][1];
					for(int l = 0; l < 8 && ok; ++l)
					{
						int tx = x + d[l][0], ty = y + d[l][1];
						if(1 > tx || tx > n || 1 > ty || ty > n)
							continue;
						if(w[tx][ty] > w[x][y])
							ok = false;
					}
				}
				if(ok)
					++p;
				ok = true;
				for(int k = 1; k <= cnt && ok; ++k)
				{
					int x = c[k][0], y = c[k][1];
					for(int l = 0; l < 8 && ok; ++l)
					{
						int tx = x + d[l][0], ty = y + d[l][1];
						if(1 > tx || tx > n || 1 > ty || ty > n)
							continue;
						if(w[tx][ty] < w[x][y])
							ok = false;
					}
				}
				if(ok)
					++v;
			}
	printf("%d %d", p, v);
	return 0;
}