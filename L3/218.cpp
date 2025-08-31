#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{ int l, r, v; }
a[1003];

void midOrder(const int &p)
{
	if(a[p].r)
		midOrder(a[p].r);
	printf("%d ", a[p].v);
	if(a[p].l)
		midOrder(a[p].l);
}

int main()
{
	int n;
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i)
		scanf("%d", &a[i].v);
	for(int i = 2; i <= n; ++i)
	{
		int p = 1;
		while(true)
			if(a[i].v <= a[p].v)
				if(a[p].l)
					p = a[p].l;
				else
				{
					a[p].l = i;
					break;
				}
			else
				if(a[p].r)
					p = a[p].r;
				else
				{
					a[p].r = i;
					break;
				}
	}
	midOrder(1);
	return 0;
}