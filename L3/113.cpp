#include <bits/stdc++.h>
using namespace std;

int a[13];

int dfs(const int &l, const int &r)
{
	if(l == r)
		return 0;
	int tot = 0;
	for(int i = l; i <= r; ++i)
		tot += a[i];
	int v = INT_MAX;
	for(int i = l; i < r; ++i)
		v = min(v, dfs(l, i) + dfs(i + 1, r));
	return v + tot;
}

int main()
{
	int n;
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i)
		scanf("%d", &a[i]);
	printf("%d", dfs(1, n));
	return 0;
}