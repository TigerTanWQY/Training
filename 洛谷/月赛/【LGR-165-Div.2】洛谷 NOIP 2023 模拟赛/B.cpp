#include <cstdio>
using namespace std;

const int a[9][9]{
	{1},
	{2, 3},
	{4, 2, 5},
	{3, 5, 1, 4},
	{5, 4, 3, 1, 2},
	{6, 1, 5, 4, 3, 2}
};

int main()
{
	int n, t;
	scanf("%d%d", &n, &t);
	if(n <= 6)
		for(int i = 1; i <= n; ++i)
		{
			for(int j = 1; j <= i; ++j)
				printf("%d ", a[i][j]);
			printf("\n");
		}
	return 0;
}