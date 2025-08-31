#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

const int INF = 0x3f3f3f3f;
vector<pair<int, int>> G[13];
bool b[13];
int dist[13], n;

void Dijkstra(const int &s, const int &t)
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
}

int main()
{
	int m, u, v;
	scanf("%d%d", &n, &m);
	while(m--)
	{
		int x, y, l;
		scanf("%d%d%d", &x, &y, &l);
		G[x].push_back(make_pair(y, l));
		G[y].push_back(make_pair(x, l));
	}
	scanf("%d%d", &u, &v);
	Dijkstra(u, v);
	if(dist[v] == INF)
		printf("No path");
	else
		printf("%d", dist[v]);
	return 0;
}