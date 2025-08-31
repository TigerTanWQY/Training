#include <bits/stdc++.h>
using namespace std;

vector<int> edges[1000003];
int pre[1000003];

void dfs(const int &p)
{
	for(const auto &x: edges[p])
		if(pre[p] != x)
		{
			pre[x] = p;
			dfs(x);
		}
}

int main()
{
	int n, u, v;
	scanf("%d", &n);
	for(int i = 1; i < n; ++i)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		edges[x].push_back(y);
		edges[y].push_back(x);
	}
	scanf("%d%d", &u, &v);
	dfs(v);
	for(; u != v; u = pre[u])
		printf("%d ", u);
	printf("%d", v);
	return 0;
}