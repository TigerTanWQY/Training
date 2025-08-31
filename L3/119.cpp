#include <bits/stdc++.h>
using namespace std;

int n, top = 0, len = 0, s[15], c[15];

void dfs(const int &i)
{
	if(!top && i == n + 1)
	{
		for(int j = 1; j <= n; ++j)
			printf("%d ", c[j]);
		printf("\n");
		return;
	}
	if(top)
	{
		int x = s[top];
		c[++len] = x;
		--top;
		dfs(i);
		s[++top] = x;
		--len;
	}
	if(i != n + 1)
	{
		s[++top] = i;
		dfs(i + 1);
		--top;
	}
}

int main()
{
	scanf("%d", &n);
	dfs(1);
	return 0;
}