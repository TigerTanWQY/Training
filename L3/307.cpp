#include <bits/stdc++.h>
using namespace std;

vector<int> edges[1000003];
int c[1000003], cnt = 0, v;
bool b[1000003];

void dfs(const int &p)
{
	b[p] = true;
	if(p == v)
	{
		for(int i = 1; i <= cnt; ++i)
			printf("%d ", c[i]);
		exit(0);
	}
	for(const auto &x: edges[p])
		if(!b[x])
		{
			c[++cnt] = x;
			dfs(x);
			--cnt;
		}
}

int main()
{
	int n, u;
	scanf("%d", &n);
	for(int i = 1; i < n; ++i)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		edges[x].push_back(y);
		edges[y].push_back(x);
	}
	scanf("%d%d", &u, &v);
	c[++cnt] = u;
	dfs(u);
	return 0;
}