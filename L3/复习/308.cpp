#include <cstdio>
#include <vector>
using namespace std;

vector<int> G[1000003];
int dist[1000003];

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
	dist[1] = 1;
	dfs(1);
	int x = 1;
	for(int i = 2; i <= n; ++i)
		if(dist[i] > dist[x])
			x = i;
	for(int i = 1; i <= n; ++i)
		dist[i] = 0;
	dist[x] = 1;
	dfs(x);
	x = dist[1];
	for(int i = 2; i <= n; ++i)
		if(dist[i] > x)
			x = dist[i];
	printf("%d", x - 1);
	return 0;
}