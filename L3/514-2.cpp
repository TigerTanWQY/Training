#include <bits/stdc++.h>
using namespace std;

int a[503], f[503][503];

int main()
{
	int n;
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i)
		scanf("%d", &a[i]);
	memset(f, 127, sizeof(f));
	for(int i = 0; i <= n; ++i)
		f[i][i] = 0;
	for(int len = 1; len < n; ++len)
		for(int i = 1; i <= n - len; ++i)
		{
			int j = i + len, s = 0;
			for(int k = i; k <= j; ++k)
				s += a[k];
			for(int k = i; k < j; ++k)
				f[i][j] = min(f[i][j], f[i][k] + f[k + 1][j]);
			f[i][j] += s;
		}
	printf("%d", f[1][n]);
	return 0;
}