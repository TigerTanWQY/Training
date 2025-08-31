#include <cstdio>
#include <algorithm>
using namespace std;

int v[33], f[20003];

int main()
{
	int m, n;
	scanf("%d%d", &m, &n);
	for(int i = 1; i <= n; ++i)
		scanf("%d", &v[i]);
	for(int i = 1; i <= n; ++i)
		for(int j = m; j >= v[i]; --j)
			f[j] = max(f[j], f[j - v[i]] + v[i]);
	printf("%d", m - f[m]);
	return 0;
}