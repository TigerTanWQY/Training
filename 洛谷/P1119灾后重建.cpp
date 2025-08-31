#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int fix[203], dis[203][203][203];

int main()
{
	int n, m, q;
	scanf("%d%d", &n, &m);
	for(int i = 0; i < n; ++i)
		scanf("%d", &fix[i]);
	memset(dis, 0x3f, sizeof(dis));
	while(m--)
	{
		int i, j, w;
		scanf("%d%d%d", &i, &j, &w);
		dis[0][i][j] = dis[0][j][i] = w;
	}
	for(int i = 0; i < n; ++i)
		dis[0][i][i] = 0;
	for(int i = 0; i < n; ++i)
		for(int j = 0; j < n; ++j)
			dis[0][i][j] = min(dis[0][i][j], dis[0][i][0] + dis[0][0][j]);
	for(int k = 1; k < n; ++k)
		for(int i = 0; i < n; ++i)
			for(int j = 0; j < n; ++j)
				dis[k][i][j] = min(dis[k - 1][i][j], dis[k - 1][i][k] + dis[k - 1][k][j]);
	scanf("%d", &q);
	while(q--)
	{
		int u, v, t;
		scanf("%d%d%d", &u, &v, &t);
		int _t = upper_bound(fix, fix + n, t) - fix - 1;
		if(t < fix[u] || t < fix[v] || dis[_t][u][v] == 0x3f3f3f3f)
			puts("-1");
		else
			printf("%d\n", dis[_t][u][v]);
	}
	return 0;
}