#include <bits/stdc++.h>
using namespace std;

const int d[4][2]{{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
int dist[1003][1003], q[1000003][2], n, m;
char s[1003][1003];

void bfs(const int &sx, const int &sy)
{
	memset(dist, 255, sizeof(dist));
	dist[sx][sy] = 0;
	int f = 1, r = 1;
	q[1][0] = sx;
	q[1][1] = sy;
	while(f <= r)
	{
		int x = q[f][0], y = q[f][1];
		++f;
		for(int i = 0; i < 4; ++i)
		{
			int tx = x + d[i][0], ty = y + d[i][1];
			if(tx < 1 || tx > n || ty < 1 || ty > m)
				continue;
			if(s[tx][ty] != 'X' && dist[tx][ty] == -1)
			{
				dist[tx][ty] = dist[x][y] + 1;
				q[++r][0] = tx;
				q[r][1] = ty;
			}
		}
	}
}

int main()
{
	scanf("%d%d", &n, &m);
	int sx, sy, ex, ey;
	for(int i = 1; i <= n; ++i)
	{
		scanf("%s", s[i] + 1);
		int l = strlen(s[i] + 1);
		for(int j = 1; j <= l; ++j)
			if(s[i][j] == 'S')
			{
				sx = i;
				sy = j;
			}
			else if(s[i][j] == 'E')
			{
				ex = i;
				ey = j;
			}
	}
	bfs(sx, sy);
	printf("%d", dist[ex][ey]);
	return 0;
}