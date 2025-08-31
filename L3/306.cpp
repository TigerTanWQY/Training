#include <bits/stdc++.h>
using namespace std;

vector<int> edges[1000003];
int a[1000003], d[1000003]{0, 1}, f[1000003], v[1000003], ans = 0;

void dfs(const int &x)
{
	f[x] = 1 << 30;
	v[x] = d[x] - a[x] + 1;
	for(const auto &y: edges[x])
	{
		d[y] = d[x] + 1;
		dfs(y);
		f[x] = min(f[x], f[y]);
		v[x] = min(v[x], v[y]);
	}
	if(f[x] > d[x])
	{
		++ans;
		f[x] = v[x];
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
	for(int i = 1; i <= n; ++i)
		scanf("%d", &a[i]);
	dfs(1);
	printf("%d", ans);
	return 0;
}