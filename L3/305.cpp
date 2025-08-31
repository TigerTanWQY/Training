#include <bits/stdc++.h>
using namespace std;

vector<int> edges[1000003];
bool b[1000003];

void dfs(const int &p, bool q)
{
	if(b[p])
		q = true;
	b[p] = q;
	for(const auto &x: edges[p])
		dfs(x, q);
}

int main()
{
	int n, m;
	scanf("%d%d", &n, &m);
	for(int i = 1; i < n; ++i)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		edges[x].push_back(y);
	}
	while(m--)
	{
		int x;
		scanf("%d", &x);
		b[x] = true;
	}
	dfs(1, false);
	for(int i = 1; i <= n; ++i)
		printf("%d", b[i]);
	return 0;
}