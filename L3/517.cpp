#include <bits/stdc++.h>
using namespace std;

int f[33][33];

int main()
{
	int n, m;
	scanf("%d%d", &n, &m);
	f[0][1] = 1;
	for(int i = 1; i <= m; ++i)
		for(int j = 1; j <= n; ++j)
		{
			int l = j - 1, r = j + 1;
			if(l < 1)
				l = n;
			if(r > n)
				r = 1;
			f[i][j] = f[i - 1][l] + f[i - 1][r];
		}
	printf("%d", f[m][1]);
	return 0;
}