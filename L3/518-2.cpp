#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e6 + 7;
int a[103], f[103][103];

int main()
{
	int n, m;
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; ++i)
		scanf("%d", &a[i]);
	f[0][0] = 1;
	for(int i = 1; i <= n; ++i)
		for(int j = 0; j <= m; ++j)
			for(int k = 0; k <= a[i]; ++k)
					f[i][j] = (f[i][j] + f[i - 1][j - k]) % MOD;
	for(int i = 1; i <= n; ++i)
	{
		for(int j = 1; j <= m; ++j)
			printf("%d ", f[i][j]);
		printf("\n");
	}
	return 0;
}