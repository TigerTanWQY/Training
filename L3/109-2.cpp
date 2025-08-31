#include <bits/stdc++.h>
using namespace std;

int n;
bool a[23];

void dfs(const int &i, const int &x)
{
	if(i == n + 1)
	{
		if(x == n - x)
		{
			for(int j = 1; j <= n; ++j)
				printf("%d", a[j]);
			printf("\n");
		}
		return;
	}
	if(x < n / 2)
	{
		a[i] = false;
		dfs(i + 1, x + 1);
	}
	if(i - 1 - x < n / 2)
	{
		a[i] = true;
		dfs(i + 1, x);
	}
}

int main()
{
	scanf("%d", &n);
	if(n % 2)
		return 0;
	dfs(1, 0);
	return 0;
}