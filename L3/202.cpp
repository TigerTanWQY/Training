#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{ int l, r; }
a[1027];

void preOrder(const int &p)
{
	printf("%d ", p);
	if(a[p].l)
		preOrder(a[p].l);
	if(a[p].r)
		preOrder(a[p].r);
}

void inOrder(const int &p)
{
	if(a[p].l)
		inOrder(a[p].l);
	printf("%d ", p);
	if(a[p].r)
		inOrder(a[p].r);
}

void postOrder(const int &p)
{
	if(a[p].l)
		postOrder(a[p].l);
	if(a[p].r)
		postOrder(a[p].r);
	printf("%d ", p);
}

int main()
{
	int n;
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i)
		scanf("%d%d", &a[i].l, &a[i].r);
	preOrder(1);
	printf("\n");
	inOrder(1);
	printf("\n");
	postOrder(1);
	return 0;
}