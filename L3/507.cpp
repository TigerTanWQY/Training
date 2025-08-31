#include <bits/stdc++.h>
using namespace std;

int v[28], p[28], f[30003];

int main()
{
	int N, m;
	scanf("%d%d", &N, &m);
	for(int i = 1; i <= m; ++i)
		scanf("%d%d", &v[i], &p[i]);
	for(int i = 1; i <= m; ++i)
		for(int j = N; j >= v[i]; --j)
			f[j] = max(f[j], f[j - v[i]] + v[i] * p[i]);
	printf("%d", f[N]);
	return 0;
}