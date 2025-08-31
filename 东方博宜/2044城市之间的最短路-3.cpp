#include <cstdio>
using namespace std;

const int INF = 0x3f3f3f3f;
int f[13][13];

int main()
{
	int n, m, x, y;
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; ++i)
	{
		for(int j = 1; j <= n; ++j)
			f[i][j] = INF;
		f[i][i] = 0;
	}
	while(m--)
	{
		int a, b, l;
		scanf("%d%d%d", &a, &b, &l);
		f[a][b] = f[b][a] = l;
	}
	scanf("%d%d", &x, &y);
	for(int k = 1; k <= n; ++k)
		for(int i = 1; i <= n; ++i)
			for(int j = 1; j <= n; ++j)
				if(f[i][k] + f[k][j] < f[i][j])
					f[i][j] = f[i][k] + f[k][j];
	if(f[x][y] == INF)
		printf("No path");
	else
		printf("%d", f[x][y]);
	return 0;
}