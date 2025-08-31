#include <bits/stdc++.h>
using namespace std;

int a[103][103][103];

int main()
{
	int n;
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i)
		for(int j = 1; j <= n; ++j)
			for(int k = 1; k <= n; ++k)
				scanf("%d", a[i][j] + k);
	for(int i = 1; i <= n; ++i)
		for(int j = 1; j <= n; ++j)
		{
			for(int k = 1; k <= n; ++k)
				printf("%d ", a[j][k][i]);
			printf("\n");
		}
	return 0;
}