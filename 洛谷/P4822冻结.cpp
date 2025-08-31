#include <cstdio>
#include <algorithm>
using namespace std;

const int INF = 0x3f3f3f3f;
struct
{ int x, y, v; }
G[2003];
int dist[53][53], n, m, k;

void bellman_ford(const int &s, const int &t)
{
	for(int i = 0; i <= n; ++i)
		for(int j = 0; j <= k; ++j)
			dist[i][j] = INF;
	dist[s][0] = 0;
	for(int _ = 1; _ <= n; ++_)
	{
		bool flag = false;
		for(int i = 1; i <= m; ++i)
		{
			int x = G[i].x, y = G[i].y, v = G[i].v;
			for(int l = 0; l <= k; ++l)
			{
				if(dist[x][l] + v < dist[y][l])
				{
					dist[y][l] = dist[x][l] + v;
					flag = true;
				}
				if(l < k && dist[x][l] + v / 2 < dist[y][l + 1])
				{
					dist[y][l + 1] = dist[x][l] + v / 2;
					flag = true;
				}
			}
		}
		if(!flag)
			break;
	}
	int ans = 0x7fffffff;
	for(int l = 0; l <= k; ++l)
		ans = min(ans, dist[t][l]);
	printf("%d", ans);
}

int main()
{
	scanf("%d%d%d", &n, &m, &k);
	m *= 2;
	for(int i = 1; i <= m; i += 2)
	{
		int x, y, v;
		scanf("%d%d%d", &x, &y, &v);
		G[i].x = x;
		G[i].y = y;
		G[i].v = v;
		G[i + 1].x = y;
		G[i + 1].y = x;
		G[i + 1].v = v;
	}
	bellman_ford(1, n);
	return 0;
}