#include <cstdio>
#include <queue>
using namespace std;
using PII = pair<long long, int>;

vector<PII> G[100003];
bool vis[100003];
int n;
long long dist[100003];

void Dijkstra(const int &s)
{
	for(int i = 1; i <= n; ++i)
	{
		dist[i] = 0x3f3f3f3f;
		vis[i] = false;
	}
	dist[s] = 0;
	priority_queue<PII, vector<PII>, greater<PII>> q;
	q.push({0, s});
	while(!q.empty())
	{
		int f = q.top().second;
		q.pop();
		if(vis[f])
			continue;
		vis[f] = true;
		for(const auto &x: G[f])
			if(dist[f] + x.second < dist[x.first])
			{
				dist[x.first] = dist[f] + x.second;
				if(!vis[x.first])
					q.push({dist[x.first], x.first});
			}
	}
}

int main()
{
	int m, s;
	scanf("%d%d%d", &n, &m, &s);
	while(m--)
	{
		int u, v, w;
		scanf("%d%d%d", &u, &v, &w);
		G[u].push_back({v, w});
	}
	Dijkstra(s);
	for(int i = 1; i <= n; ++i)
		printf("%lld ", dist[i]);
	return 0;
}