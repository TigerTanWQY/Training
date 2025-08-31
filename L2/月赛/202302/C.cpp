#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n, m;
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= (n - m) / 2; ++i)
	{
		for(int j = 1; j <= n; ++j)
			printf("#");
		printf("\n");
	}
	for(int i = 1; i <= m; ++i)
	{
		for(int j = 1; j <= (n - m) / 2; ++j)
			printf("#");
		for(int j = 1; j <= m; ++j)
			printf("+");
		for(int j = 1; j <= (n - m) / 2; ++j)
			printf("#");
		printf("\n");
	}
	for(int i = 1; i <= (n - m) / 2; ++i)
	{
		for(int j = 1; j <= n; ++j)
			printf("#");
		printf("\n");
	}
	return 0;
}