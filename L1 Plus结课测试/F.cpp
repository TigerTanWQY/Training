#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n, m;
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= m; ++i)
	{
		for(int j = 1; j < n + i; ++j)
			printf("+");
		printf("\n");
	}
	return 0;
}