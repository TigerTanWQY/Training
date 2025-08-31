#include <cstdio>
#include <vector>
using namespace std;

vector<int> G[1003];
int a[1003], c[1003], f[1003], cnt;
bool vis[1003];

void dfs(const int &p, const int &l)
{
	vis[p] = true;
	if(++c[a[p]] == 1)
		++cnt;
	if(p > l)
		++f[cnt];
	for(const auto &x: G[p])
		if(!vis[x])
			dfs(x, l);
	if(--c[a[p]] == 0)
		--cnt;
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
		scanf("%d", &a[i]);
	for(int i = 1; i <= n; ++i)
	{
		cnt = 0;
		dfs(i, i);
		for(int j = 1; j <= n; ++j)
		{
			vis[j] = false;
			c[j] = 0;
		}
	}
	for(int i = 1; i <= n; ++i)
		printf("%d ", f[i]);
	return 0;
}