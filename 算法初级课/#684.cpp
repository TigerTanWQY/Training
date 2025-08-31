#include <cstdio>
#include <algorithm>
using namespace std;

const int INF = 0x3f3f3f3f;
int dist[303][303];

int main()
{
	int n, m, q;
	scanf("%d%d%d", &n, &m, &q);
	for(int i = 0; i <= n; ++i)
	{
		for(int j = 0; j <= n; ++j)
			dist[i][j] = INF;
		dist[i][i] = 0;
	}
	while(m--)
	{
		int x, y, z;
		scanf("%d%d%d", &x, &y, &z);
		dist[x][y] = z;
	}
	for(int k = 1; k <= n; ++k) //±ê×¼Floyd
		for(int i = 1; i <= n; ++i)
			for(int j = 1; j <= n; ++j)
				dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
	while(q--)
	{
		int s, t;
		scanf("%d%d", &s, &t);
		if(dist[s][t] == INF)
			printf("-1");
		else
			printf("%d\n", dist[s][t]);
	}
	return 0;
}