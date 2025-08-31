#include <bits/stdc++.h>
using namespace std;

const int N = 1003;
int a[N][N], c[N], d[N][N], dp[N], n, m, p;

struct Queue
{
	int h, t, q[N], g[N];
	void init()
	{
		h = 1;
		t = 0;
	}
	void add(const int &x, const int &y)
	{
		g[x] = y;
		for(; h <= t && g[x] >= g[q[t]]; --t);
		++t;
		q[t] = x;
	}
	int queue(const int &x)
	{
		for(; h <= t && q[h] < x - p; ++h);
		return g[q[h]];
	}
} g[N];

int main()
{
	scanf("%d%d%d", &n, &m, &p);
	for(int i = 0; i < n; ++i)
		for(int j = 1; j <= m; ++j)
			scanf("%d", &a[j][i]);
	for(int i = 0; i < n; ++i)
	{
		scanf("%d", &c[i]);
		g[i].init();
	}
	for(int i = 1; i <= m; ++i)
		for(int j = 0; j < n; ++j)
			d[i][j] = d[i - 1][j] + a[i][(j + i - 1) % n];
	for(int i = 1; i <= m; ++i)
	{
		dp[i] = INT_MIN;
		for(int s = 0; s < n; ++s)
		{
			g[s].add(i - 1, dp[i - 1] - d[i - 1][s] - c[(i - 1 + s) % n]);
			dp[i] = max(dp[i], g[s].queue(i) + d[i][s]);
		}
	}
	printf("%d", dp[m]);
	return 0;
}