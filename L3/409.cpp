#include <bits/stdc++.h>
using namespace std;

vector<int> edges[20003];
int q[20003], dist[20003], a[13], k, l;

void bfs()
{
	memset(dist, 255, sizeof(dist)); //³õÊ¼»¯Îª-1
	int f = 1, r = 0;
	for(int i = 1; i <= k; ++i)
	{
		q[++r] = a[i];
		dist[a[i]] = 0;
	}
	while(f <= r)
	{
		int x = q[f++];
		for(const auto &y: edges[x])
			if(dist[y] == -1)
			{
				dist[y] = dist[x] + 1;
				q[++r] = y;
			}
	}
}

int main()
{
	int n, m, p;
	scanf("%d%d%d", &n, &m, &p);
	while(m--)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		edges[x].push_back(y);
		edges[y].push_back(x);
	}
	while(p--)
	{
		scanf("%d", &k);
		for(int i = 1; i <= k; ++i)
			scanf("%d", &a[i]);
		bfs();
		int ans = 20002;
		scanf("%d", &l);
		while(l--)
		{
			int b;
			scanf("%d", &b);
			if(dist[b] != -1)
				ans = min(ans, dist[b]);
		}
		if(ans == 20002)
			ans = -1;
		printf("%d\n", ans);
	}
	return 0;
}