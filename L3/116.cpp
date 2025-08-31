#include <bits/stdc++.h>
using namespace std;

int n, m, p[13], a[13], c[85];

void dfs(const int &i)
{
	if(i == m + 1)
	{
		for(int j = 1; j <= m; ++j)
			printf("%d ", c[j]);
		printf("\n");
		return;
	}
	for(int j = 1; j <= n; ++j)
		if(a[j] != p[j])
		{
			c[i] = j;
			++a[j];
			dfs(i + 1);
			--a[j];
		}
}

int main()
{
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i)
		scanf("%d", &p[i]);
	for(int i = 1; i <= n; ++i)
		m += p[i];
	dfs(1);
	return 0;
}