#include <cstdio>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;

const int INF = 0x3f3f3f3f;
set<pair<int, int>> q;
vector<pair<int, int>> G[100003];
int dist[100003], n, m;

inline int Dijkstra(const int &s, const int &t)
{
	for(int i = 1; i <= n; ++i)
		dist[i] = INF;
	dist[s] = 0;
	q.clear();
	for(int i = 1; i <= n; ++i)
		q.insert(make_pair(dist[i], i));
	while(!q.empty())
	{
		int f = q.cbegin()->second;
		q.erase(q.cbegin());
		if(f == t || dist[f] >= INF)
			break;
		for(const auto &p: G[f])
			if(dist[f] + p.second < dist[p.first])
			{
				q.erase(make_pair(dist[p.first], p.first));
				dist[p.first] = dist[f] + p.second;
				q.insert(make_pair(dist[p.first], p.first));
			}
	}
	return dist[t];
}

int main()
{
	int k;
	scanf("%d%d%d", &n, &m, &k);
	while(m--)
	{
		int x, y, z;
		scanf("%d%d%d", &x, &y, &z);
		G[x].push_back(make_pair(y, z));
	}
	while(k--)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		int ans = Dijkstra(x, y);
		if(ans == INF)
			printf("-1\n");
		else
			printf("%d\n", ans);
	}
	return 0;
}