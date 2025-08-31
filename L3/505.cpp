#include <bits/stdc++.h>
using namespace std;

int v[1003], w[1003], f[1003][1003];

int main()
{
	int n, m;
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; ++i)
		scanf("%d%d", &v[i], &w[i]);
	memset(f, 128, sizeof(f));
	f[0][0] = 0;
	for(int i = 1; i <= n; ++i)
		for(int j = 0; j <= m; ++j)
		{
			f[i][j] = f[i - 1][j];
			if(j >= v[i])
				f[i][j] = max(f[i][j], f[i - 1][j - v[i]] + w[i]);
		}
	int ans = 0;
	for(int j = 0; j <= m; ++j)
		ans = max(ans, f[n][j]);
	printf("%d", ans);
	return 0;
}