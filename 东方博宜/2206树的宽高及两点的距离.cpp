#include <cstdio>
#include <cstdlib>
#include <vector>
using namespace std;

vector<int> G[1003], cnt[1003];
bool vis[1003];
int maxd = 0;

void dfs(const int &p, const int &d)
{
	vis[p] = true;
	maxd = max(maxd, d);
	cnt[d].push_back(p);
	for(const auto &x: G[p])
		if(!vis[x])
			dfs(x, d + 1);
}

void solve(const int &u, const int &v, const int &l)
{
	vis[u] = true;
	if(u == v)
	{
		printf("%d", l);
		return;
	}
	for(const auto &x: G[u])
		if(!vis[x])
			solve(x, v, l + 1);
}

int main()
{
	int n, u, v, maxw = 0;
	scanf("%d", &n);
	for(int i = 1; i < n; ++i)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		G[x].push_back(y);
		G[y].push_back(x);
	}
	scanf("%d%d", &u, &v);
	dfs(1, 1);
	printf("%d\n", maxd);
	for(int i = 1; i <= maxd; ++i)
		maxw = max(maxw, (int)cnt[i].size());
	printf("%d\n", maxw);
	for(int i = 1; i <= n; ++i)
		vis[i] = false;
	solve(u, v, 0);
	return 0;
}