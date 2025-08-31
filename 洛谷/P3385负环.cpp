#include <cstdio>
using namespace std;

const int INF = 0x3f3f3f3f;
struct
{ int x, y, v; }
G[6003];
int dist[2003], n, m = 0;

bool BellmanFord(const int &s)
{
	for(int i = 1; i <= n; ++i)
		dist[i] = INF;
	dist[s] = 0;
	bool ret = false;
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
			ret = true;
			break;
		}
	}
	if(ret)
	{
		bool flag = false;
		for(int i = 1; i <= m && !flag; ++i)
			if(G[i].x == s)
				flag = true;
		ret = flag;
	}
	return ret;
}

int main()
{
	int T;
	scanf("%d", &T);
	while(T--)
	{
		int cnt;
		scanf("%d%d", &n, &cnt);
		while(cnt--)
		{
			int u, v, w;
			scanf("%d%d%d", &u, &v, &w);
			G[++m] = {u, v, w};
			if(w >= 0)
				G[++m] = {v, u, w};
		}
		if(BellmanFord(1))
			printf("YES\n");
		else
			printf("NO\n");
		m = 0;
	}
	return 0;
}