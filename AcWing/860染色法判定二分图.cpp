#include <cstdio>
#include <set>
using namespace std;

const int N = 100003;
set<int> G[N];
int st[N];

bool dfs(const int &p, const int &col)
{
	st[p] = col;
	for(const auto &x: G[p])
		if(!st[x])
		{
			if(!dfs(x, 3 - col))
				return false;
		}
		else if(st[x] == col)
			return false;
	return true;
}

int main()
{
	int n, m;
	scanf("%d%d", &n, &m);
	for(int u, v; m--; )
	{
		scanf("%d%d", &u, &v);
		G[u].insert(v);
		G[v].insert(u);
	}
	bool flag = true;
	for(int i = 1; i <= n && flag; ++i)
		if(!st[i] && !dfs(i, 1))
			flag = false;
	printf(flag? "Yes": "No");
	return 0;
}
