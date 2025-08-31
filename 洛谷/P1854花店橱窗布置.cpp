#include <cstdio>
#include <algorithm>
using namespace std;

const int N = 103;
int d[N][N], f[N][N], pre[N][N];

void print(const int &x, const int &y)
{
	if(pre[x][y] == y)
	{
		printf("%d ", y);
		return;
	}
	print(x - 1, pre[x][y]);
	printf("%d ", y);
}

int main()
{
	int F, V;
	scanf("%d%d", &F, &V);
	for(int i = 1; i <= F; ++i)
		for(int j = 1; j <= V; ++j)
			scanf("%d", &d[i][j]);
	for(int i = 1; i <= V - F; ++i)
	{
		f[1][i] = d[1][i];
		pre[1][i] = i;
	}
	for(int i = 2; i <= F; ++i)
		for(int j = i; j <= V - F + i; ++j)
			for(int k = 1; k < j; ++k)
				if(f[i - 1][k] + d[i][j] > f[i][j])
				{
					f[i][j] = f[i - 1][k] + d[i][j];
					pre[i][j] = k;
				}
	int tx = F, ty = -1, ans = 0;
	for(int i = F; i <= V; ++i)
		if(f[F][i] > ans)
		{
			ans = f[F][i];
			ty = i;
		}
	printf("%d\n", ans);
	print(tx, ty);
	return 0;
}