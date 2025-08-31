#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;

const int N = 4003;
vector<int> G[N];
bool vis[N];
vector<int> match[N];

bool dfs(const int &u)
{
	for(const auto &v: G[u])
		if(!vis[v])
		{
			vis[v] = true;
			if(match[v].size() < 2)
			{
				match[v].push_back(u);
				return true;
			}
			else if(dfs(match[v][0]))
			{
				match[v][0] = u;
				return true;
			}
			else if(dfs(match[v][1]))
			{
				match[v][1] = u;
				return true;
			}
		}
	return false;
}

int main()
{
	int n, ans = 0;
	scanf("%d", &n);
	for(int i = 1, x, y; i <= 2 * n; ++i)
	{
		scanf("%d%d", &x, &y);
		G[i].push_back(x);
		G[i].push_back(y);
		match[i].reserve(3);
	}
	for(int i = 1; i <= 2 * n; ++i)
	{
		memset(vis, false, sizeof(bool) * 2 * n + 1);
		if(dfs(i))
			++ans;
	}
	printf("%d", ans);
	return 0;
}
