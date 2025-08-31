#include <bits/stdc++.h>
using namespace std;

struct
{ int l, r, fa; }
a[1003];
int b[1003], c[1003];

int main()
{
	int n, u, v;
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i)
	{
		scanf("%d%d", &a[i].l, &a[i].r);
		if(a[i].l)
			a[a[i].l].fa = i;
		if(a[i].r)
			a[a[i].r].fa = i;
	}
	scanf("%d%d", &u, &v);
	int l1 = 0;
	for(; u != 1; u = a[u].fa)
		b[++l1] = u;
	b[++l1] = 1;
	for(int i = 1, j = l1; i < j; ++i, --j)
		swap(b[i], b[j]);
	int l2 = 0;
	for(; v != 1; v = a[v].fa)
		c[++l2] = v;
	c[++l2] = 1;
	for(int i = 1, j = l2; i < j; ++i, --j)
		swap(c[i], c[j]);
	int x = 0;
	for(int i = 1; i <= l1 && i <= l2; ++i)
		if(b[i] == c[i])
			x = b[i];
		else
			break;
	printf("%d", x);
	return 0;
}