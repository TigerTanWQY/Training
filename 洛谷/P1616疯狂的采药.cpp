#include <cstdio>
#include <algorithm>
using namespace std;

int a[10003], b[10003];
long long f[10000003];

int main()
{
	int t, m;
	scanf("%d%d", &t, &m);
	for(int i = 1; i <= m; ++i)
		scanf("%d%d", &a[i], &b[i]);
	for(int i = 1; i <= m; ++i)
		for(int j = a[i]; j <= t; ++j)
			f[j] = max(f[j], f[j - a[i]] + b[i]);
	printf("%lld", f[t]);
	return 0;
}