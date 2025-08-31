#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

const int INF = 0x3f3f3f3f;
pair<int, int> a[103];
bool f[103][103];
int n;
double G[103][103][103][103], d[103][103];

void Dijkstra(const int &sx, const int &sy, const int &ex, const int &ey)
{
	for(int i = 1; i <= n; ++i)
		for(int j = 1; j <= n; ++j)
			d[i][j] = INF;
	d[sx][sy] = 0;
	for(int _ = 0; _ < n; ++_)
	{
		int x = -1, y = -1;
		for(int i = 1; i <= n; ++i)
			for(int j = 1; j <= n; ++j)
				if(!f[i][j] && (x == -1 || y == -1 || d[i][j] < d[x][y]))
				{
					x = i;
					y = j;
				}
		if((x == ex && y == ey) || (x == -1 || y == -1))
			break;
		f[x][y] = true;
		for(int i = 1; i <= n; ++i)
			for(int j = 1; j <= n; ++j)
				if(!f[i][j] && G[x][y][i][j] && d[x][y] + G[x][y][i][j] < d[i][j])
					d[i][j] = d[x][y] + G[x][y][i][j];
	}
}

int main()
{
	int m, s, t;
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		a[i] = make_pair(x, y);
	}
	scanf("%d", &m);
	while(m--)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		int x1 = a[x].first, y1 = a[x].second, x2 = a[y].first, y2 = a[y].second;
		G[x1][y1][x2][y2] = G[x2][y2][x1][y1] = sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
	}
	scanf("%d%d", &s, &t);
	int sx = a[s].first, sy = a[s].second, ex = a[t].first, ey = a[t].second;
	Dijkstra(sx, sy, ex, ey);
	printf("%.2lf", d[ex][ey]);
	return 0;
}