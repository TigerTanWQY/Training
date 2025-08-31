#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

const int INF = 0x3f3f3f3f;
vector<pair<int, int>> G[5003];
bool b[5003];
int dist[5003], n, m;

inline int Dijkstra(const int &s, const int &t)
{
	for(int i = 1; i <= n; ++i)
	{
		b[i] = false;
		dist[i] = INF;
	}
	dist[s] = 0;
	while(true)
	{
		int x = -1;
		for(int i = 1; i <= n; ++i)
			if(!b[i] && dist[i] < INF && (x == -1 || dist[i] < dist[x]))
				x = i;
		if(x == t || x == -1)
			break;
		b[x] = true;
		for(const auto &p: G[x])
			if(dist[x] + p.second < dist[p.first])
				dist[p.first] = dist[x] + p.second;
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