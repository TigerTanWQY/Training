#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;

const int N = 103;
vector<int> G[103];
bool vis[N];
int match[N];

bool dfs(const int &u)
{
	for(const auto &v: G[u])
		if(!vis[v])
		{
			vis[v] = true;
			if(!match[v] || dfs(match[v]))
			{
				match[v] = u;
				return true;
			}
		}
	return false;
}

int main()
{
	int m, n, ans = 0;
	scanf("%d%d", &m, &n);
	for(int u, v; ; )
	{
		scanf("%d%d", &u, &v);
		if(u == -1 && v == -1)
			break;
		G[u].push_back(v);
	}
	for(int i = 1; i <= m; ++i)
	{
		memset(vis, false, sizeof(vis));
		if(dfs(i))
			++ans;
	}
	printf("%d\n", ans);
	for(int i = m + 1; i <= n; ++i)
		if(match[i])
			printf("%d %d\n", match[i], i);
	return 0;
}
