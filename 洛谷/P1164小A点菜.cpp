#include <cstdio>
using namespace std;

int a[103], f[103][10003];

int main()
{
	int n, m;
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; ++i)
		scanf("%d", &a[i]);
	for(int i = 1; i <= n; ++i)
		for(int j = 1; j <= m; ++j)
		{
			if(j == a[i])
				f[i][j] = f[i - 1][j] + 1;
			if(j > a[i])
				f[i][j] = f[i - 1][j] + f[i - 1][j - a[i]];
			if(j < a[i])
				f[i][j] = f[i - 1][j];
		}
	printf("%d", f[n][m]);
	return 0;
}