#include <bits/stdc++.h>
using namespace std;

struct
{ int l, r, v; }
a[1003];
int cnt;

void dfs(const int &p)
{
	cnt += a[p].v;
	if(a[p].l)
		dfs(a[p].l);
	if(a[p].r)
		dfs(a[p].r);
}

int main()
{
	int n;
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i)
		scanf("%d%d", &a[i].l, &a[i].r);
	for(int i = 1; i <= n; ++i)
		scanf("%d", &a[i].v);
	for(int i = 1; i <= n; ++i)
	{
		cnt = 0;
		dfs(i);
		printf("%d ", cnt);
	}
	return 0;
}