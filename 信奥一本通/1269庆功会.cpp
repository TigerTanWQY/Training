#include <bits/stdc++.h>
using namespace std;

int v[503], w[503], s[503], f[6003], c[13];

int main()
{
	int n, m;
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; ++i)
		scanf("%d%d%d", &v[i], &w[i], &s[i]);
	for(int i = 1; i <= n; ++i)
	{
		int tot = 0, x = 1;
		for(; x <= s[i]; x *= 2)
		{
			c[++tot] = x;
			s[i] -= x;
		}
		c[++tot] = s[i];
		for(int k = 1; k <= tot; ++k)
			for(int j = m; j >= v[i] * c[k]; --j)
				f[j] = max(f[j], f[j - v[i] * c[k]] + w[i] * c[k]);
	}
	printf("%d", f[m]);
	return 0;
}