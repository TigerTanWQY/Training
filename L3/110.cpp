#include <bits/stdc++.h>
using namespace std;

int n, m;
int a[17];

void dfs(const int &i)
{
	if(i != 1)
	{
		for(int j = 1; j < i; ++j)
			printf("%d ", a[j]);
		printf("\n");
	}
	if(i == n + 1)
		return;
	for(int j = 1; j <= m; ++j)
		if(j != a[i - 1])
		{
			a[i] = j;
			dfs(i + 1);
		}
}

int main()
{
	scanf("%d%d", &n, &m);
	dfs(1);
	return 0;
}