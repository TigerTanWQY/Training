#include <bits/stdc++.h>
using namespace std;

int n, a[13];
bool b[13];

void dfs(const int &i)
{
	if(i == n + 1)
	{
		for(int j = 1; j <= n; ++j)
			printf("%d ", a[j]);
		printf("\n");
		return;
	}
	for(int j = 1; j <= n; ++j)
		if(!b[j])
		{
			b[j] = true;
			a[i] = j;
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