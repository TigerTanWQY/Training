#include <cstdio>
#include <vector>
using namespace std;

vector<int> G[1000003];
int pre[1000003];

void dfs(const int &p)
{
	for(const auto &x: G[p])
		if(pre[p] != x)
		{
			pre[x] = p;
			dfs(x);
		}
}

int main()
{
	int n, s, e;
	scanf("%d", &n);
	for(int i = 1; i < n; ++i)
	{
		int u, v;
		scanf("%d%d", &u, &v);
		G[u].push_back(v);
		G[v].push_back(u);
	}
	scanf("%d%d", &s, &e);
	dfs(e);
	for(; s != e; s = pre[s])
		printf("%d ", s);
	printf("%d", s);
	return 0;
}