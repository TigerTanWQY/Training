#include <bits/stdc++.h>
using namespace std;

int n, x, ans = 2e9;
int a[23];

void dfs(const int &i, const int &tot) //选或不选
{
	ans = min(ans, abs(tot - x));
	if(i == n + 1)
		return;
	dfs(i + 1, tot + a[i]);
	dfs(i + 1, tot);
}

int main()
{
	scanf("%d%d", &n, &x);
	for(int i = 1; i <= n; ++i)
		scanf("%d", &a[i]);
	dfs(1, 0);
	printf("%d", ans);
	return 0;
}