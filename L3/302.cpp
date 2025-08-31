#include <bits/stdc++.h>
using namespace std;

vector<int> edges[100003];
int v[100003];
long long d[100003];

long long dfs(const int &p)
{
	d[p] = v[p];
	for(const auto &x: edges[p])
		d[p] += dfs(x);
	return d[p];
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
	for(int i = 1; i <= n; ++i)
		scanf("%d", &v[i]);
	dfs(1);
	for(int i = 1; i <= n; ++i)
		printf("%lld ", d[i]);
	return 0;
}