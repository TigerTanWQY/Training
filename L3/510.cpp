#include <bits/stdc++.h>
using namespace std;

int v[2003], w[2003], l[2003], f[2003], c[2003];

int main()
{
	int n, m;
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; ++i)
		scanf("%d%d%d", &v[i], &w[i], &l[i]);
	for(int i = 1; i <= n; ++i)
	{
		int tot = 0, x = 1;
		for(; x <= l[i]; x *= 2)
		{
			c[++tot] = x;
			l[i] -= x;
		}
		c[++tot] = l[i];
		for(int k = 1; k <= tot; ++k)
			for(int j = m; j >= v[i] * c[k]; --j)
				f[j] = max(f[j], f[j - v[i] * c[k]] + w[i] * c[k]);
	}
	printf("%d", f[m]);
	return 0;
}