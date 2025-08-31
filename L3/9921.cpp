#include <bits/stdc++.h>
using namespace std;

int l[1000003], r[1000003], a[1000003], ans = 1;
bool flag = false;

int dfs(const int &x, const int &y, const int &s)
{
	if(x == -1 && y == -1)
		return 0;
	if(x == -1 || (y == -1 && x != y))
	{
		flag = true;
		return 0;
	}
	if(a[x] != a[y])
	{
		flag = true;
		return 0;
	}
	return dfs(l[x], r[y], 2) + dfs(r[x], l[y], 2) + s;
}

int main()
{
	int n;
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i)
		scanf("%d", &a[i]);
	for(int i = 1; i <= n; ++i)
		scanf("%d%d", &l[i], &r[i]);
	for(int i = 1; i <= n; ++i)
	{
		int s = dfs(l[i], r[i], 3);
		if(s > ans && !flag)
			ans = s;
		flag = false;
	}
	printf("%d", ans);
	return 0;
}