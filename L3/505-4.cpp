#include <bits/stdc++.h>
using namespace std;

int v[1003], w[1003], f[1003];

int main()
{
	int n, m;
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; ++i)
		scanf("%d%d", &v[i], &w[i]);
	for(int i = 1; i <= n; ++i)
		for(int j = m; j >= v[i]; --j)
			f[j] = max(f[j], f[j - v[i]] + w[i]);
	printf("%d", f[m]);
	return 0;
}