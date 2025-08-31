#include <cstdio>
#include <set>
#include <queue>
using namespace std;

set<int> G[13];
bool vis[13];

void bfs(const int &root)
{
	queue<int> q;
	vis[root] = true;
	q.push(root);
	while(!q.empty())
	{
		int f = q.front();
		q.pop();
		printf("%d ", f);
		for(const auto &x: G[f])
			if(!vis[x])
			{
				vis[x] = true;
				q.push(x);
			}
	}
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
	bfs(1);
	return 0;
}