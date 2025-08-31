#include <bits/stdc++.h>
using namespace std;

int n, c[13]{-1};
bool b[13];

void dfs(const int &i)
{
	if(i == n + 1)
	{
		for(int j = 1; j <= n; ++j)
			printf("%d ", c[j]);
		printf("\n");
		return;
	}
	for(int j = 1; j <= n; ++j)
		if(!b[j] && j != c[i - 1] + 1)
		{
			c[i] = j;
			b[j] = true;
			dfs(i + 1);
			b[j] = false;
		}
}

int main()
{
	scanf("%d", &n);
	dfs(1);
	return 0;
}