#include <cstdio>
using namespace std;

int par[103], deg[103];

int main()
{
	int n, m, root, maxDeg = 0, maxNum = 1;
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= m; ++i)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		par[y] = x;
	}
	for(int i = 1; i <= n; ++i)
	{
		if(par[i] == 0)
			root = i;
		deg[par[i]]++;
	}
	printf("%d\n", root);
	for(int i = 1; i <= n; ++i)
	{
		if(deg[i] > maxDeg)
		{
			maxDeg = deg[i];
			maxNum = i;
		}
	}
	printf("%d\n", maxNum);
	for(int i = 1; i <= n; ++i)
	{
		if(par[i] == maxNum)
			printf("%d ", i);
	}
	return 0;
}