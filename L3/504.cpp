#include <bits/stdc++.h>
using namespace std;

int a[1003], b[1003], f[1003][1003];

int main()
{
	int n, m;
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; ++i)
		scanf("%d", &a[i]);
	for(int i = 1; i <= m; ++i)
		scanf("%d", &b[i]);
	for(int i = 1; i <= n; ++i)
		for(int j = 1; j <= m; ++j)
		{
			f[i][j] = max(f[i - 1][j], f[i][j - 1]);
			if(a[i] == b[j])
				f[i][j] = max(f[i][j], f[i - 1][j - 1] + 1);
		}
	printf("%d", f[n][m]);
	return 0;
}