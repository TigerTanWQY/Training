#include <bits/stdc++.h>
using namespace std;

int w[103], p[103], f[20003];

int main()
{
	int maxw, n;
	scanf("%d%d", &maxw, &n);
	for(int i = 1; i <= n; ++i)
		scanf("%d%d", &w[i], &p[i]);
	for(int i = 1; i <= n; ++i)
		for(int j = maxw; j >= w[i]; --j)
			f[j] = max(f[j], f[j - w[i]] + p[i]);
	printf("%d", f[maxw]);
	return 0;
}