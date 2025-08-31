#include <bits/stdc++.h>
using namespace std;

struct Edge
{
	int to, l;
	Edge(const int &x, const int &y)
	: to(x), l(y)
	{ }
};
vector<Edge> edges[20003];
vector<int> c[20003];
int dist[20003];

int main()
{
	int n, m, k;
	scanf("%d%d%d", &n, &m, &k);
	while(m--)
	{
		int x, y, z;
		scanf("%d%d%d", &x, &y, &z);
		edges[x].push_back(Edge(y, z));
		edges[y].push_back(Edge(x, z));
	}
	while(k--)
	{
		int u, v;
		scanf("%d%d", &u, &v);
		memset(dist, 255, sizeof(dist));
		for(int i = 0; i <= n; ++i)
			c[i].clear();
		dist[u] = 0;
		c[0].push_back(u);
		for(int i = 0; ; ++i)
		{
			int f = 0, r = c[i].size() - 1;
			while(f <= r)
			{
				int x = c[i][f++];
				for(const auto y: edges[x])
					if(!y.l && dist[y.to] == -1)
					{
						dist[y.to] = dist[x];
						c[i].push_back(y.to);
						++r;
					}
			}
			if(dist[v] != -1)
				break;
			for(const auto j: c[i])
				for(const auto y: edges[j])
					if(y.l && dist[y.to] == -1)
					{
						dist[y.to] = dist[j] + 1;
						c[i + 1].push_back(y.to);
					}
			if(c[i + 1].empty())
				break;
		}
		printf("%d\n", dist[v]);
	}
	return 0;
}