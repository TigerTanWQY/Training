#include <cstdio>
using namespace std;

const int INF = 0x3f3f3f3f;
struct
{ int x, y, v; }
G[5003];
int dist[5003], n, m;

inline int bellman_ford(const int &s, const int &t)
{
	for(int i = 1; i <= n; ++i)
		dist[i] = INF;
	dist[s] = 0;
	for(int cnt = 1; ; ++cnt)
	{
		bool flag = false;
		for(int i = 1; i <= m; ++i)
		{
			int x = G[i].x, y = G[i].y, v = G[i].v;
			if(dist[x] + v < dist[y])
			{
				dist[y] = dist[x] + v;
				flag = true;
			}
		}
		if(!flag)
			break;
		if(cnt > n)
		{
			dist[t] = INF;
			break;
		}
	}
	return dist[t];
}

int main()
{
	int k;
	scanf("%d%d%d", &n, &m, &k);
	for(int i = 1; i <= m; ++i)
	{
		int x, y, v;
		scanf("%d%d%d", &x, &y, &v);
		G[i].x = x;
		G[i].y = y;
		G[i].v = v;
	}
	while(k--)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		int ans = bellman_ford(x, y);
		if(ans == INF)
			printf("-1\n");
		else
			printf("%d\n", ans);
	}
	return 0;
}