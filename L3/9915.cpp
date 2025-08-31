#include <bits/stdc++.h>
using namespace std;

int a[19][19], f[19][19], w[19], v[19][19], rec[19], ans = INT_MAX;
int n, m, r, c;

inline void dps()
{
	memset(f, 127, sizeof(f));
	memset(w, 0, sizeof(w));
	memset(v, 0, sizeof(v));
	for(int i = 1; i <= m; ++i)
		for(int j = 1; j < r; ++j)
			w[i] += abs(a[rec[j]][i] - a[rec[j + 1]][i]);
	for(int i = 1; i <= m; ++i)
		for(int j = i + 1; j <= m; ++j)
			for(int k = 1; k <= r; ++k)
				v[i][j] += abs(a[rec[k]][i] - a[rec[k]][j]);
	f[0][0] = 0;
	for(int i = 1; i <= c; ++i)
		for(int j = i; j <= m; ++j)
			for(int k = 0; k < j; ++k)
				f[i][j] = min(f[i][j], f[i - 1][k] + w[j] + v[k][j]);
	for(int i = c; i <= m; ++i)
		ans = min(ans, f[c][i]);
}

void dfs(const int &x, const int &y)
{
	if(y > r)
	{
		dps();
		return;
	}
	if(x > n)
		return;
	dfs(x + 1, y);
	rec[y] = x;
	dfs(x + 1, y + 1);
}

int main()
{
	scanf("%d%d%d%d", &n, &m, &r, &c);
	for(int i = 1; i <= n; ++i)
		for(int j = 1; j <= m; ++j)
			scanf("%d", &a[i][j]);
	dfs(1, 1);
	printf("%d", ans);
	return 0;
}