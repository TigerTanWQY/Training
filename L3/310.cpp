#include <bits/stdc++.h>
using namespace std;

vector<int> edges[1003];
int dist[1003], ans[1003];

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
	for(int i = 1; i <= n; ++i)
	{
		memset(dist, 0, sizeof(dist));
		dist[i] = 1;
		dfs(i);
		for(int j = i + 1; j <= n; ++j)
			++ans[dist[j] - 1];
	}
	for(int i = 1; i < n; ++i)
		printf("%d ", ans[i]);
	return 0;
}