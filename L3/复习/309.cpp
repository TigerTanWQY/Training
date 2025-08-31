#include <cstdio>
#include <vector>
using namespace std;

vector<int> G[1003];
bool vis[1003];
int maxd;

void dfs(const int &p, const int &d)
{
	vis[p] = true;
	maxd = max(maxd, d);
	for(const auto &x: G[p])
		if(!vis[x])
			dfs(x, d + 1);
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
		maxd = 0;
		for(int j = 1; j <= n; ++j)
			vis[j] = false;
		dfs(i, 1);
		printf("%d ", maxd);
	}
	return 0;
}