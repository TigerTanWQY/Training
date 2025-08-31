#include <cstdio>
#include <algorithm>
using namespace std;

const int INF = 0x3f3f3f3f;
struct
{ int x, y, v; }
G[20003];
int f[3][5003], n, m;

void bellman_ford(const int &s, const int &id)
{
	for(int i = 1; i <= n; ++i)
		f[id][i] = INF;
	f[id][s] = 0;
	while(true)
	{
		bool flag = false;
		for(int i = 1; i <= m; ++i)
		{
			int x = G[i].x, y = G[i].y, v = G[i].v;
			if(f[id][x] + v < f[id][y])
			{
				f[id][y] = f[id][x] + v;
				flag = true;
			}
		}
		if(!flag)
			break;
	}
}

int main()
{
	int a, b, c, ans = 0x7fffffff;
	scanf("%d%d", &n, &m);
	m *= 2;
	for(int i = 1; i <= m; i += 2)
	{
		int x, y, z;
		scanf("%d%d%d", &x, &y, &z);
		G[i].x = x;
		G[i].y = y;
		G[i].v = z;
		G[i + 1].x = y;
		G[i + 1].y = x;
		G[i + 1].v = z;
	}
	scanf("%d%d%d", &a, &b, &c);
	bellman_ford(a, 0);
	bellman_ford(b, 1);
	bellman_ford(c, 2);
	for(int i = 1; i <= n; ++i)
		ans = min(ans, f[0][i] + f[1][i] + f[2][i]);
	printf("%d", ans);
	return 0;
}