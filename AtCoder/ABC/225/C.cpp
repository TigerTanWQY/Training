#include <cstdio>
using namespace std;

int b[10003][10003], x[10003][10003], y[10003][10003];

int main()
{
	int n, m;
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; ++i)
		for(int j = 1; j <= m; ++j)
			scanf("%d", &b[i][j]);
	for(int i = 1; i <= n; ++i)
		for(int j = 1; j <= m; ++j)
		{
			x[i][j] = (b[i][j] + 6) / 7;
			y[i][j] = (b[i][j] - 1) % 7 + 1;
		}
	bool flag = true;
	for(int i = 1; i <= n && flag; ++i)
		for(int j = 1; j <= m && flag; ++j)
			flag = !((1 < i && x[i][j] != x[i - 1][j] + 1) || (1 < j && y[i][j] != y[i][j - 1] + 1) || (1 < j && x[i][j] != x[i][j - 1]) || (1 < i && y[i][j] != y[i - 1][j]));
	if(flag)
		printf("Yes");
	else
		printf("No");
	return 0;
}