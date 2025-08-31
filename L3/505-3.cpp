#include <bits/stdc++.h>
using namespace std;

int v[1003], w[1003], f[1003], g[1003];

int main()
{
	int n, m;
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; ++i)
		scanf("%d%d", &v[i], &w[i]);
	for(int i = 1; i <= n; ++i)
	{
		for(int j = 0; j <= m; ++j)
		{
			g[j] = f[j];
			if(j >= v[i])
				g[j] = max(g[j], f[j - v[i]] + w[i]);
		}
		memcpy(f, g, sizeof(f));
		//memset(g, 0, sizeof(g));
	}
	printf("%d", f[m]);
	return 0;
}