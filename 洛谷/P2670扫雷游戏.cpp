#include <cstdio>
using namespace std;

char a[103][103];

int main()
{
	int n, m;
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; ++i)
		scanf("%s", a[i] + 1);
	for(int i = 1; i <= n; ++i)
	{
		for(int j = 1; j <= m; ++j)
			if(a[i][j] == '*')
				printf("*");
			else
				printf("%d", (a[i - 1][j - 1] == '*') + (a[i - 1][j] == '*') + (a[i - 1][j + 1] == '*') + (a[i][j - 1] == '*') + (a[i][j + 1] == '*') + (a[i + 1][j - 1] == '*') + (a[i + 1][j] == '*') + (a[i + 1][j + 1] == '*'));
		printf("\n");
	}
	return 0;
}