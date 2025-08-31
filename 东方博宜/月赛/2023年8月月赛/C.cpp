#include <cstdio>
using namespace std;

int a[53][53], cost[2503][53];
/* 代价 = 路径上经过的单元格的值之和 + 移动的代价之和 */
int main()
{
	int m, n;
	scanf("%d%d", &m, &n);
	for(int i = 0; i < m; ++i)
		for(int j = 0; j < n; ++j)
			scanf("%d", &a[i][j]);
	for(int i = 0; i < m * n; ++i)
		for(int j = 0; j < n; ++j)
			scanf("%d", &cost[i][j]);
	for(int sj = 0; sj < n; ++sj)
		for(int ej = 0; ej < n; ++ej)
			;
	return 0;
}