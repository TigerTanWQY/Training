#include <bits/stdc++.h>
using namespace std;

int v[103], w[103], l[103], f[103];

int main()
{
	int n, m;
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; ++i)
		scanf("%d%d%d", &v[i], &w[i], &l[i]);
	for(int i = 1; i <= n; ++i)
		while(l[i]--)
			for(int j = m; j >= v[i]; --j)
				f[j] = max(f[j], f[j - v[i]] + w[i]);
	printf("%d", f[m]);
	return 0;
}