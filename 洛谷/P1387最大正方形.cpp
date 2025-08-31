#include <cstdio>
#include <algorithm>
using namespace std;

int a[103][103], f[103][103];

int main()
{
	int n, m, ans = 0;
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; ++i)
		for(int j = 1; j <= m; ++j)
		{
			scanf("%d", &a[i][j]);
			if(a[i][j] == 1)
				f[i][j] = min(min(f[i][j - 1], f[i - 1][j]), f[i - 1][j - 1]) + 1;
			ans = max(ans, f[i][j]);
		}
	printf("%d", ans);
	return 0;
}