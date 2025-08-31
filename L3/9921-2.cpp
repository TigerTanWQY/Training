#include <bits/stdc++.h>
using namespace std;

int a[1000003], l[1000003], r[1000003], sz[1000003];

void dfs(const int &u)
{
	sz[u] = 1;
	if(l[u] != -1)
	{
		dfs(l[u]);
		sz[u] += sz[l[u]];
	}
	if(r[u] != -1)
	{
		dfs(r[u]);
		sz[u] += sz[r[u]];
	}
}

bool check(const int &u, const int &v)
{
	if(u == -1 && v == -1)
		return true;
	if(u == -1 || v == -1)
		return false;
	if(a[u] != a[v])
		return false;
	return check(l[u], r[v]) && check(l[v], r[u]);
}

int main()
{
	int n, ans = 0;
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i)
		scanf("%d", &a[i]);
	for(int i = 1; i <= n; ++i)
		scanf("%d%d", &l[i], &r[i]);
	dfs(1);
	for(int i = 1; i <= n; ++i)
		if(check(l[i], r[i]))
			ans = max(ans, sz[i]);
	printf("%d", ans);
	return 0;
}