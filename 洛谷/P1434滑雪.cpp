#include <cstdio>
#include <algorithm>
using namespace std;

const int d[][2]{{0, -1}, {-1, 0}, {1, 0}, {0, 1}};
int a[103][103], f[103][103], r, c;

int dfs(const int &x, const int &y)
{
	if(f[x][y])
		return f[x][y];
	f[x][y] = 1;
	for(int i = 0; i < 4; ++i)
	{
		int tx = x + d[i][0], ty = y + d[i][1];
		if(1 <= tx && tx <= r && 1 <= ty && ty <= c && a[x][y] > a[tx][ty])
		{
			dfs(tx, ty);
			f[x][y] = max(f[x][y], f[tx][ty] + 1);
		}
	}
	return f[x][y];
}

int main()
{
	scanf("%d%d", &r, &c);
	for(int i = 1; i <= r; ++i)
		for(int j = 1; j <= c; ++j)
			scanf("%d", &a[i][j]);
	int ans = 0;
	for(int x = 1; x <= r; ++x)
		for(int y = 1; y <= c; ++y)
			ans = max(ans, dfs(x, y));
	printf("%d", ans);
	return 0;
}