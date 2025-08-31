#include <bits/stdc++.h>
using namespace std;

vector<int> edges[20003];
int q[20003], dist[20003];

void bfs(const int &p)
{
	memset(dist, 0, sizeof(dist));
	int f = 1, r = 0;
	q[++r] = p;
	dist[p] = 1;
	while(f <= r)
	{
		int x = q[f++];
		for(const auto &y: edges[x])
			if(!dist[y])
			{
				dist[y] = dist[x] + 1;
				q[++r] = y;
			}
	}
}

int main()
{
	int n, m, k;
	scanf("%d%d%d", &n, &m, &k);
	for(int i = 1; i <= m; ++i)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		edges[x].push_back(y);
		edges[y].push_back(x);
	}
	while(k--)
	{
		int u, v;
		scanf("%d%d", &u, &v);
		bfs(u);
		printf("%d\n", dist[v] - 1);
	}
	return 0;
}