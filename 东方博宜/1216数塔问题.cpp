#include <bits/stdc++.h>
using namespace std;

int a[103][103], f[103][103];

int main()
{
	int n;
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i)
		for(int j = 1; j <= i; ++j)
			scanf("%d", &a[i][j]);
	for(int j = 1; j <= n; ++j)
		f[n][j] = a[n][j];
	for(int i = n - 1; i >= 1; --i)
		for(int j = 1; j <= i; ++j)
			f[i][j] = a[i][j] + max(f[i + 1][j], f[i + 1][j + 1]);
	printf("%d", f[1][1]);
	return 0;
}