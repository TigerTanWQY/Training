#include <bits/stdc++.h>
using namespace std;

vector<int> edges[100003];
int d[100003]{0, 1};

void dfs(const int &p)
{
	for(auto x: edges[p])
	{
		d[x] = d[p] + 1;
		dfs(x);
	}
}

int main()
{
	int n;
	scanf("%d", &n);
	for(int i = 1; i < n; ++i)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		edges[x].push_back(y);
	}
	dfs(1);
	for(int i = 1; i <= n; ++i)
		printf("%d ", d[i]);
	return 0;
}