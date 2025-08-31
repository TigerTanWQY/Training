#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;

const int N = 503;
vector<int> G[N];
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
	int n1, n2, m, ans = 0;
	scanf("%d%d%d", &n1, &n2, &m);
	for(int u, v; m--; )
	{
		scanf("%d%d", &u, &v);
		G[u].push_back(v);
	}
	for(int i = 1; i <= n1; ++i)
	{
		memset(vis, false, sizeof(vis));
		if(dfs(i))
			++ans;
	}
	printf("%d", ans);
	return 0;
}
