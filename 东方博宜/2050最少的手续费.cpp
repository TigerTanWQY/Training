#include <cstdio>
#include <vector>
#include <queue>
using namespace std;

const int INF = 0x3f3f3f3f;
vector<pair<int, double>> G[2003];
bool vis[2003];
double dis[2003];

void Dijkstra(const int &s)
{
	priority_queue<pair<double, int>> q;
	q.push(make_pair(1, s));
	while(!q.empty())
	{
		int x = q.top().second;
		q.pop();
		if(vis[x])
			continue;
		vis[x] = true;
		for(const auto &p: G[x])
		{
			int v = p.first;
			double l = p.second;
			if(!vis[v] && dis[v] < dis[x] * l)
			{
				dis[v] = dis[x] * l;
				q.push(make_pair(dis[v], v));
			}
		}
	}
}

int main()
{
	int n, m, s, t;
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; ++i)
		dis[i] = -INF;
	while(m--)
	{
		int x, y, z;
		scanf("%d%d%d", &x, &y, &z);
		G[x].push_back(make_pair(y, 1 - z / 100.0));
		G[y].push_back(make_pair(x, 1 - z / 100.0));
	}
	scanf("%d%d", &s, &t);
	dis[s] = true;
	Dijkstra(s);
	printf("%.8lf", 100 / dis[t]);
	return 0;
}