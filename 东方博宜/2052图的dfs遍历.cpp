#include <cstdio>
#include <set>
using namespace std;

set<int> G[13];
bool vis[13];

void dfs(const int &p)
{
	vis[p] = true;
	printf("%d ", p);
	for(const auto &x: G[p])
		if(!vis[x])
			dfs(x);
}

int main()
{
	int n, e;
	scanf("%d%d", &n, &e);
	while(e--)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		G[x].insert(y);
		G[y].insert(x);
	}
	dfs(1);
	return 0;
}