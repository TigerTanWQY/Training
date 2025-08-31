#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;
using LL = long long;
using PII = pair<int, int>;

vector<PII> G[3003];
bool vis[3003];
int t[3003], dist[3003], n, m;
LL h[3003];

bool SPFA(const int &s)
{
	queue<int> q;
	memset(h, 0x3f, sizeof(h));
	h[s] = 0;
	vis[s] = true;
	q.push(s);
	while(!q.empty())
	{
		int f = q.front();
		q.pop();
		vis[f] = 0;
		for(const auto &x: G[f])
			if(h[f] + x.second < h[x.first])
			{
				h[x.first] = h[f] + x.second;
				if(!vis[x.first])
				{
					vis[x.first] = true;
					q.push(x.first);
					++t[x.first];
					if(t[x.first] == n + 1)
						return false;
				}
			}
	}
	return true;
}

void Dijkstra(const int &s)
{
	priority_queue<PII, vector<PII>, greater<PII>> q;
	for(int i = 1; i <= n; ++i)
	{
		dist[i] = 1e9;
		vis[i] = false;
	}
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
	scanf("%d%d", &n, &m);
	while(m--)
	{
		int u, v, w;
		scanf("%d%d%d", &u, &v, &w);
		G[u].push_back({v, w});
	}
	for(int i = 1; i <= n; ++i)
		G[0].push_back({i, 0});
	if(!SPFA(0))
	{
		printf("-1");
		return 0;
	}
	for(int u = 1; u <= n; ++u)
		for(auto &x: G[u])
			x.second += h[u] - h[x.second];
	for(int i = 1; i <= n; ++i)
	{
		Dijkstra(i);
		LL ans = 0;
		for(int j = 1; j <= n; ++j)
			if(dist[j] == 1e9)
				ans += j * 1e9;
			else
				ans += j * (dist[j] + h[j] - h[i]);
		printf("%lld\n", ans);
	}
	return 0;
}