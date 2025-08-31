#include <cstdio>
#include <set>
using namespace std;

set<int> edges[200003];
bool vis[200003];

void dfs(const int &p)
{
	vis[p] = true;
	printf("%d ", p);
	for(const auto &x: edges[p])
		if(!vis[x])
		{
			dfs(x);
			printf("%d ", p);
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
		edges[x].insert(y);
		edges[y].insert(x);
	}
	dfs(1);
	return 0;
}