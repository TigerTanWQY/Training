#include <bits/stdc++.h>
using namespace std;

int n, m, ans;
int v[23], w[23];

void dfs(const int &i, const int &tot, const int &vol)
{
	if(vol > m)
		return;
	ans = max(ans, tot);
	if(i == n + 1)
		return;
	dfs(i + 1, tot + w[i], vol + v[i]);
	dfs(i + 1, tot, vol);
}

int main()
{
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; ++i)
		scanf("%d%d", &v[i], &w[i]);
	dfs(1, 0, 0);
	printf("%d", ans);
	return 0;
}