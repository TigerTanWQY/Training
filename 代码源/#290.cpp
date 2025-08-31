#include <cstdio>
using namespace std;

int f[13][13]{{0}, {0, 1}, {0, 1, 1}};

int main()
{
	int n;
	scanf("%d", &n);
	for(int i = 3; i <= n; ++i)
		for(int j = 1; j <= i; ++j)
			f[i][j] = f[i - 1][j - 1] + f[i - 1][j];
	for(int i = 1; i <= n; ++i)
	{
		for(int j = 1; j <= i; ++j)
			printf("%d ", f[i][j]);
		printf("\n");
	}
	return 0;
}