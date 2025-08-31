#include <bits/stdc++.h>
using namespace std;

int a[503];
long long f[503][503];

int main()
{
	int n;
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i)
		scanf("%d", &a[i]);
	memset(f, 127, sizeof(f));
	for(int i = 1; i <= n; ++i)
		f[i][i + 1] = 0;
	for(int d = 2; d < n; ++d)
		for(int i = 1; i <= n - d; ++i)
		{
			int j = i + d;
			for(int k = i + 1; k < j; ++k)
				f[i][j] = min(f[i][j], f[i][k] + f[k][j] + a[i] * a[j] * a[k]);
		}
	if(n == 1)
		printf("0");
	else
		printf("%lld", f[1][n]);
	return 0;
}