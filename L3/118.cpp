#include <bits/stdc++.h>
using namespace std;

int n, c[15];

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
	{
		bool flag = true;
		for(int k = 1; k < i && flag; ++k)
			if(c[k] == j || (k + c[k] == i + j) || (k - c[k] == i - j))
				flag = false;
		if(flag)
		{
			c[i] = j;
			dfs(i + 1);
		}
	}
}

int main()
{
	scanf("%d", &n);
	dfs(1);
	return 0;
}