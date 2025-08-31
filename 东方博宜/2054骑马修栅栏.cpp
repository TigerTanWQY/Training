#include <cstdio>
#include <algorithm>
using namespace std;

const int N = 503;
int a[N][N], d[N], p[2 * N], k = 0, minn = 501, maxn = 0;

void dfs(const int &x)
{
	for(int i = minn; i <= maxn; ++i)
	{
		if(a[x][i])
		{
			--a[x][i];
			--a[i][x];
			dfs(i);
		}
	}
	p[++k] = x;
}

int main()
{
	int F;
	scanf("%d", &F);
	while(F--)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		++a[x][y];
		++a[y][x];
		++d[x];
		++d[y];
		minn = min(minn, min(x, y));
		maxn = max(maxn, max(x, y));
	}
	int x = minn;
	for(int i = minn; i <= maxn; ++i)
		if(d[i] % 2)
		{
			x = i;
			break;
		}
	dfs(x);
	for(int i = k; i; --i)
		printf("%d\n", p[i]);
	return 0;
}