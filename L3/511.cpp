#include <bits/stdc++.h>
using namespace std;

int a[1003], v[1003], w[1003], f[1003][1003];
vector<int> c[1003];

int main()
{
	int n, m;
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; ++i)
	{
		scanf("%d%d%d", &a[i], &v[i], &w[i]);
		c[a[i]].push_back(i);
	}
	for(int i = 1; i <= 1000; ++i)
		for(int j = 0; j <= m; ++j)
		{
			f[i][j] = f[i - 1][j];
			for(const auto &k: c[i])
				if(j >= v[k])
					f[i][j] = max(f[i][j], f[i - 1][j - v[k]] + w[k]);
		}
	printf("%d", f[1000][m]);
	return 0;
}