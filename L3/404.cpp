#include <bits/stdc++.h>
using namespace std;

vector<int> edges[20003];
bool b[20003];

void dfs(const int &p)
{
	b[p] = true;
	for(const auto &x: edges[p])
		if(!b[x])
			dfs(x);
}

int main()
{
	int n, m;
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= m; ++i)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		edges[x].push_back(y);
		edges[y].push_back(x);
	}
	int ans = 0;
	for(int i = 1; i <= n; ++i)
		if(!b[i])
		{
			++ans;
			dfs(i);
		}
	printf("%d", ans);
	return 0;
}