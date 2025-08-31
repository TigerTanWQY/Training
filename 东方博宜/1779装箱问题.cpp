#include <bits/stdc++.h>
using namespace std;

int v[33], V, n, ans;

void dfs(const int &i, const int &w)
{
	if(i > n)
	{
		if(V >= w)
			ans = min(ans, V - w);
		return;
	}
	dfs(i + 1, w);
	dfs(i + 1, w + v[i]);
}

int main()
{
	scanf("%d%d", &V, &n);
	ans = V;
	for(int i = 1; i <= n; ++i)
		scanf("%d", &v[i]);
	dfs(1, 0);
	printf("%d", ans);
	return 0;
}