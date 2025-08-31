#include <bits/stdc++.h>
using namespace std;

struct
{ int l, r, v; }
a[1000003];
int f[1000003];

int dfs(const int &p)
{
	f[p] = a[p].v;
	if(a[p].l)
		f[p] += dfs(a[p].l);
	if(a[p].r)
		f[p] += dfs(a[p].r);
	return f[p];
}

int main()
{
	int n;
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i)
		scanf("%d%d", &a[i].l, &a[i].r);
	for(int i = 1; i <= n; ++i)
		scanf("%d", &a[i].v);
	dfs(1);
	for(int i = 1; i <= n; ++i)
		printf("%d ", f[i]);
	return 0;
}