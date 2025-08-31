#include <bits/stdc++.h>
using namespace std;

int v[103], w[103], f[1003];

int main()
{
	int t, m;
	scanf("%d%d", &t, &m);
	for(int i = 1; i <= m; ++i)
		scanf("%d%d", &v[i], &w[i]);
	for(int i = 1; i <= m; ++i)
		for(int j = t; j >= v[i]; --j)
			f[j] = max(f[j], f[j - v[i]] + w[i]);
	printf("%d", f[t]);
	return 0;
}