#include <cstdio>
#include <vector>
using namespace std;

vector<int> G[1003];
int dist[1003], ans[1003];

void dfs(const int &p)
{
	for(const auto &x: G[p])
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
		G[x].push_back(y);
		G[y].push_back(x);
	}
	for(int i = 1; i <= n; ++i)
	{
		for(int j = 1; j <= n; ++j)
			dist[j] = 0;
		dist[i] = 1;
		dfs(i);
		for(int j = i + 1; j <= n; ++j)
			++ans[dist[j] - 1];
	}
	for(int i = 1; i < n; ++i)
		printf("%d ", ans[i]);
	return 0;
}