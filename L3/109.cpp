#include <bits/stdc++.h>
using namespace std;

int n;
bool a[23];

void dfs(const int &i)
{
	if(i == n + 1)
	{
		int t = 0;
		for(int j = 1; j <= n; ++j)
			if(a[j])
				++t;
		if(t == n - t)
		{
			for(int j = 1; j <= n; ++j)
				printf("%d", a[j]);
			printf("\n");
		}
		return;
	}
	a[i] = false;
	dfs(i + 1);
	a[i] = true;
	dfs(i + 1);
}

int main()
{
	scanf("%d", &n);
	dfs(1);
	return 0;
}