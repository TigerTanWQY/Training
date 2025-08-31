#include <bits/stdc++.h>
using namespace std;

int w[33], c[33], f[203];

int main()
{
	int m, n;
	scanf("%d%d", &m, &n);
	for(int i = 1; i <= n; ++i)
		scanf("%d%d", &w[i], &c[i]);
	for(int i = 1; i <= n; ++i)
		for(int j = m; j >= w[i]; --j)
			f[j] = max(f[j], f[j - w[i]] + c[i]);
	printf("%d", f[m]);
	return 0;
}