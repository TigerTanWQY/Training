#include <bits/stdc++.h>
using namespace std;

int v[103], w[103], t[103], f[103][103];

int main()
{
	int n, m, k;
	scanf("%d%d%d", &n, &m, &k);
	for(int i = 1; i <= n; ++i)
		scanf("%d%d%d", &v[i], &w[i], &t[i]);
	for(int i = 1; i <= n; ++i)
		for(int j = m; j >= v[i]; --j)
			for(int x = k; x >= t[i]; --x)
				if(j < v[i] || x < t[i])
					f[j][x] = f[j][x];
				else
					f[j][x] = max(f[j][x], f[j - v[i]][x - t[i]] + w[i]);
	printf("%d", f[m][k]);
	return 0;
}