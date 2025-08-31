#include <cstdio>
using namespace std;

int a[103][103];

int main()
{
	int n;
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i)
		for(int j = 1; j <= n; ++j)
			a[i][j] = n * (i - 1) + j;
	for(int i = 1; i <= n; ++i)
	{
		for(int j = 1; j <= n; ++j)
			printf("%d ", a[i][j]);
		printf("\n");
	}
	for(int j = 1; j <= n; ++j)
	{
		for(int i = 1; i <= n; ++i)
			printf("%d ", a[i][j]);
		printf("\n");
	}
	return 0;
}