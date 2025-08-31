#include <cstdio>
using namespace std;

const int INF = 0x3f3f3f3f;
int f[103][103];

int main()
{
	int n, m;
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; ++i)
	{
		for(int j = 1; j <= n; ++j)
			f[i][j] = INF;
		f[i][i] = 0;
	}
	while(m--)
	{
		int u, v, w;
		scanf("%d%d%d", &u, &v, &w);
		if(w < f[u][v])
			f[u][v] = f[v][u] = w;
	}
	for(int k = 1; k <= n; ++k)
		for(int i = 1; i <= n; ++i)
			for(int j = 1; j <= n; ++j)
				if(f[i][k] + f[k][j] < f[i][j])
					f[i][j] = f[i][k] + f[k][j];
	for(int i = 1; i <= n; ++i)
	{
		for(int j = 1; j <= n; ++j)
			printf("%d ", f[i][j]);
		printf("\n");
	}
	return 0;
}