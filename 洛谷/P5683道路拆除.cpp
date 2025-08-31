#include <cstdio>
#include <cstring>
#include <queue>
#include <algorithm>
using namespace std;

const int N = 3003, M = 6003;
int cnte, h[N], to[M], nx[M], dis[3][N];

inline void adde(const int &u, const int &v)
{
	nx[++cnte] = h[u];
	to[cnte] = v;
	h[u] = cnte;
}

inline void bfs(const int &rt, int* const d)
{
	queue<int> q;
	d[rt] = 0;
	q.push(rt);
	while(!q.empty())
	{
		int u = q.front();
		q.pop();
		for(int i = h[u]; i; i = nx[i])
		{
			int v = to[i];
			if(d[v] > d[u] + 1)
			{
				d[v] = d[u] + 1;
				q.push(v);
			}
		}
	}
}

int main()
{
	int n, m, s1, t1, s2, t2, ans = 2e9;
	scanf("%d%d", &n, &m);
	while(m--)
	{
		int u, v;
		scanf("%d%d", &u, &v);
		adde(u, v);
		adde(v, u);
	}
	scanf("%d%d%d%d", &s1, &t1, &s2, &t2);
	memset(dis, 0x3f, sizeof(dis));
	bfs(1, dis[0]);
	bfs(s1, dis[1]);
	bfs(s2, dis[2]);
	for(int i = 1; i <= n; ++i)
		if(dis[0][i] + dis[1][i] <= t1 && dis[0][i] + dis[2][i] <= t2)
			ans = min(ans, dis[0][i] + dis[1][i] + dis[2][i]);
	if(ans == 2e9)
		ans = -1;
	else
		ans = cnte / 2 - ans;
	printf("%d", ans);
	return 0;
}