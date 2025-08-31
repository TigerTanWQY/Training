#include <bits/stdc++.h>
using namespace std;

int n, c[48]{1};

void dfs(const int &i, const int &s)
{
	if(s == 0)
	{
		for(int j = 1; j < i; ++j)
			printf("%d ", c[j]);
		printf("\n");
		return;
	}
	for(int j = c[i - 1]; j <= s; ++j)
	{
		c[i] = j;
		dfs(i + 1, s - j);
	}
}

int main()
{
	scanf("%d", &n);
	dfs(1, n);
	return 0;
}