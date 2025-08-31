#include <bits/stdc++.h>
using namespace std;

int a[503], f[503][503];

int dfs(const int &l, const int &r)
{
	if(l == r)
		return 0;
	if(f[l][r])
		return f[l][r];
	int s = 0, v = INT_MAX;
	for(int i = l; i <= r; ++i)
		s += a[i];
	for(int i = l; i < r; ++i)
		v = min(v, dfs(l, i) + dfs(i + 1, r));
	return f[l][r] = v + s;
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