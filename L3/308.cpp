#include <bits/stdc++.h>
using namespace std;

vector<int> edges[1000003];
int dist[1000003]{0, 1};

void dfs(const int &p)
{
	for(const auto &x: edges[p])
		if(!dist[x])
		{
			dist[x] = dist[p] + 1;
			dfs(x);
		}
}

int main()
{
	int n;
	scanf("%d", &n);
	for(int i = 1; i < n; ++i)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		edges[x].push_back(y);
		edges[y].push_back(x);
	}
	dfs(1);
	int y = 1;
	for(int i = 2; i <= n; ++i)
		if(dist[i] > dist[y])
			y = i;
	memset(dist, 0, sizeof(dist));
	dist[y] = 1;
	dfs(y);
	int ans = 0;
	for(int i = 1; i <= n; ++i)
		ans = max(ans, dist[i]);
	printf("%d", ans - 1);
	return 0;
}