#include <cstdio>
using namespace std;

const int INF = 0x3f3f3f3f;
struct
{ int x, y, v; }
G[200003];
int dist[20003], n, m;

void BellmanFord(const int &s)
{
	for(int i = 1; i <= n; ++i)
		dist[i] = INF;
	dist[s] = 0;
	while(true)
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
	}
}

int main()
{
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= m; ++i)
	{
		int u, v, l;
		scanf("%d%d%d", &u, &v, &l);
		G[i].x = u;
		G[i].y = v;
		G[i].v = l;
	}
	BellmanFord(1);
	for(int i = 2; i <= n; ++i)
		printf("%d\n", dist[i]);
	return 0;
}