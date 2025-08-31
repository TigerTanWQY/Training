#include <cstdio>
using namespace std;

const int MOD = 998'244'353;
int a[48][48], b[48][48], n, m, ans = 0;

void dfs(const int &x, const int &y, const int &ex, const int &ey, const int &tot)
{
	if(1 > x || x > n || 1 > y || y > m || tot < 0)
		return;
	if(tot == 0 && (x != ex || y != ey))
		return;
	if(tot == 0)
		ans = (ans + 1) % MOD;
	else
	{
		dfs(x + 1, y, ex, ey, tot - a[x + 1][y]);
		dfs(x, y + 1, ex, ey, tot - b[x][y + 1]);
	}
}

int main()
{
	int k;
	scanf("%d%d%d", &n, &m, &k);
	for(int i = 1; i <= n; ++i)
		for(int j = 1; j <= m; ++j)
			scanf("%d", &a[i][j]);
	for(int i = 1; i <= n; ++i)
		for(int j = 1; j <= m; ++j)
			scanf("%d", &b[i][j]);
	for(int x = 1; x <= n; ++x)
	{
		ans = 0;
		for(int y = 1; y <= m; ++y)
		{
			dfs(1, 1, x, y, 0);
			printf("%d ", ans);
		}
		printf("\n");
	}
	return 0;
}