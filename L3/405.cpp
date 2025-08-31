#include <bits/stdc++.h>
using namespace std;

bool b[11];
int a[11][11], n, ans = 80001;

void dfs(const int &x, const int &y, const int &z)
{
	if(y == n)
	{
		ans = min(ans, z + a[x][1]);
		return;
	}
	for(int i = 1; i <= n; ++i)
		if(!b[i])
		{
			b[i] = true;
			dfs(i, y + 1, z + a[x][i]);
			b[i] = false;
		}
}

int main()
{
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i)
		for(int j = 1; j <= n; ++j)
			scanf("%d", &a[i][j]);
	b[1] = true;
	dfs(1, 1, 0);
	b[1] = false;
	printf("%d", ans);
	return 0;
}