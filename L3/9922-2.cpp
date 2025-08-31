#include <bits/stdc++.h>
using namespace std;

int p[103][103], f[10003];

int main()
{
	int t, n, m;
	scanf("%d%d%d", &t, &n, &m);
	for(int i = 1; i <= t; ++i)
		for(int j = 1; j <= n; ++j)
			scanf("%d", &p[i][j]);
	for(int i = 1; i < t; ++i)
	{
		memset(f, 0, sizeof(f));
		for(int j = 1; j <= n; ++j)
			for(int k = p[i][j]; k <= m; ++k)
				f[k] = max(f[k], f[k - p[i][j]] + p[i + 1][j] - p[i][j]);
		m += f[m];
	}
	printf("%d", m);
	return 0;
}