#include <bits/stdc++.h>
using namespace std;

int p[1003][1003], f[10003];

int main()
{
	int t, n, m;
	scanf("%d%d%d", &t, &n, &m);
	for(int i = 1; i <= t; ++i)
		for(int j = 1; j <= n; ++j)
			scanf("%d", &p[j][i]);
	for(int k = 1; k < t; ++k)
	{
		memset(f, 0, sizeof(f));
		for(int i = 1; i <= n; ++i)
			for(int j = p[i][k]; j <= m; ++j)
				f[j] = max(f[j], f[j - p[i][k]] + p[i][k + 1] - p[i][k]);
		m += f[m];
	}
	printf("%d", m);
	return 0;
}