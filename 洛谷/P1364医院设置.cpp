#include <cstdio>
#include <cstring>
using namespace std;

const int INF = 0x7fffffff;
int v[503], x[503], dis[503], f[503][503], n;

void Dijkstra(const int &k)
{
	memset(v, 0, sizeof(v));
	for(int i = 1; i <= n; ++i)
		dis[i] = f[k][i];
	dis[k] = 0;
	v[k] = 1;
	for(int i = 1; i < n; ++i)
	{
		int maxn = INF, k1 = -1;
		for(int j = 1; j <= n; ++j)
			if(!v[j] && dis[j] < maxn)
			{
				maxn = dis[j];
				k1 = j;
			}
		if(k1 == -1)
			break;
		v[k1] = 1;
		for(int j = 1; j <= n; ++j)
		{
			if(!v[j] && dis[k1] + 1 < dis[j] && f[k1][j] == 1)
				dis[j] = dis[k1] + 1;
		}
	}
}

int main()
{
	memset(f, 0x7f, sizeof(f));
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i)
	{
		int y, z;
		scanf("%d%d%d", &x[i], &y, &z);
		f[i][y] = f[y][i] = f[i][z] = f[z][i] = 1;
	}
	int ans = INF;
	for(int i = 1; i <= n; ++i)
	{
		memset(dis, 0x7f, sizeof(dis));
		int tot = 0;
		Dijkstra(i);
		for(int j = 1; j <= n; ++j)
			if(i != j)
				tot += x[j] * dis[j];
		if(tot < ans)
			ans = tot;
	}
	printf("%d", ans);
	return 0;
}