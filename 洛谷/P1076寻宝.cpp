#include <cstdio>
using namespace std;

const int MOD = 20123;
int pd[10003][103], a[10003][103];

int main()
{
	int n, m, x, ans = 0;
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; ++i)
	{
		int l = 0;
		for(int j = 0; j < m; ++j)
		{
			scanf("%d %d", &pd[i][j], &a[i][j]);
			if(pd[i][j])
				++l;
		}
		pd[i][m] = l;
	}
	scanf("%d", &x);
	for(int i = 1, j; i <= n; x = j, ++i)
	{
		ans = (ans + a[i][x]) % MOD;
		int k = 0;
		for(j = x; ; ++j)
		{
			if(j == m)
				j = 0;
			if(pd[i][j])
				++k;
			if(k == (a[i][x] - 1) % pd[i][m] + 1)
				break;
		}
		x = j;
	}
	printf("%d", ans);
	return 0;
}