#include <cstdio>
#include <algorithm>
using namespace std;

bool G1[11][11], G2[11][11];
int p[11];

int main()
{
	int n, m;
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= m; ++i)
	{
		int u, v;
		scanf("%d%d", &u, &v);
		G1[u][v] = G1[v][u] = true;
	}
	for(int i = 1; i <= m; ++i)
	{
		int u, v;
		scanf("%d%d", &u, &v);
		G2[u][v] = G2[v][u] = true;
	}
	for(int i = 1; i <= n; ++i)
		p[i] = i;
	do
	{
		bool flag = true;
		for(int i = 1; i <= n && flag; ++i)
			for(int j = 1; j <= n && flag; ++j)
				if(G1[i][j] != G2[p[i]][p[j]])
					flag = false;
		if(flag)
		{
			printf("Yes");
			return 0;
		}
	} while(next_permutation(p + 1, p + n + 1));
	printf("No");
	return 0;
}