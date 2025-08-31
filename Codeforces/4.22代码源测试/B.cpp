#include <bits/stdc++.h>
using namespace std;

int a[123];
int m, n, ans = 0, len = 1;

void dfs(const int &i, const int &k, const int &tot)
{
	if(tot > n || i > len)
		return;
	if(tot == n)
	{
		ans = max(ans, k);
		return;
	}
	dfs(i + 1, k + 1, tot ^ a[i]);
	dfs(i + 1, k + 1, tot);
}

int main()
{
	int T;
	scanf("%d", &T);
	while(T--)
	{
		ans = 0;
		len = 1;
		scanf("%d%d", &m, &n);
		for(int i = 1; i <= m; ++i)
			len *= 2;
		for(int i = 1; i <= len; ++i)
			a[i] = i - 1;
		dfs(1, 0, 0);
		printf("%d\n", ans);
	}
	return 0;
}