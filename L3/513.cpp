#include <bits/stdc++.h>
using namespace std;

int a[1003], v[1003], w[1003], l[1003], f[1003], c[1003];

int main()
{
	int n, m;
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; ++i)
	{
		scanf("%d%d%d", &a[i], &v[i], &w[i]);
		if(a[i] == 3)
			scanf("%d", &l[i]);
	}
	for(int i = 1; i <= n; ++i)
		switch(a[i])
		{
			case 1:
				for(int j = m; j >= v[i]; --j)
					f[j] = max(f[j], f[j - v[i]] + w[i]);
				break;
			case 2:
				for(int j = v[i]; j <= m; ++j)
					f[j] = max(f[j], f[j - v[i]] + w[i]);
				break;
			case 3:
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
		}
	printf("%d", f[m]);
	return 0;
}