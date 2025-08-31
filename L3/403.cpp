#include <bits/stdc++.h>
using namespace std;

vector<int> edges[1003];
int cnt = 0;
bool b[1003];

void dfs(const int &p)
{
	b[p] = true;
	++cnt;
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
	}
	for(int i = 1; i <= n; ++i)
	{
		dfs(i);
		memset(b, false, sizeof(b));
	}
	printf("%d", cnt);
	return 0;
}