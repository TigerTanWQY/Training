#include <bits/stdc++.h>
using namespace std;

const int N = 1003;
bool g[N][N], vis[N];
int a[N], b[N], dp[N], n;

int calc(const int &u)
{
	if(dp[u] != -1)
		return dp[u];
	dp[u] = 0;
	for(int v = 1; v <= n; ++v)
		if(g[u][v])
			dp[u] = max(dp[u], calc(v) + 1);
	return dp[u];
}

int main()
{
	int m, ans = 0;
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= m; ++i)
	{
		int x, y = 0;
		scanf("%d", &x);
		memset(vis, false, sizeof(vis));
		for(int j = 0; j < x; ++j)
		{
			scanf("%d", &a[j]);
			vis[a[j]] = true;
		}
		for(int j = a[0]; j <= a[x - 1]; ++j)
			if(!vis[j])
				b[y++] = j;
		for(int j = 0; j < x; ++j)
			for(int k = 0; k < y; ++k)
				g[a[j]][b[k]] = true;
	}
	memset(dp, 255, sizeof(dp));
	for(int i = 1; i <= n; ++i)
		ans = max(ans, calc(i));
	printf("%d", ans + 1);
	return 0;
}