#include <bits/stdc++.h>
using namespace std;

struct
{ int l, r, v; }
a[1000003];
int n, f[1000003], c[1000003];

void bfs(const int &root)
{
	c[1] = root;
	int front = 1, rear = 1;
	while(front <= rear)
	{
		int p = c[front++];
		if(a[p].l)
			c[++rear] = a[p].l;
		if(a[p].r)
			c[++rear] = a[p].r;
	}
	for(int i = n; i; --i)
	{
		int p = c[i];
		f[p] = a[p].v;
		if(a[p].l)
			f[p] += f[a[p].l];
		if(a[p].r)
			f[p] += f[a[p].r];
	}
}

int main()
{
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i)
		scanf("%d%d", &a[i].l, &a[i].r);
	for(int i = 1; i <= n; ++i)
		scanf("%d", &a[i].v);
	bfs(1);
	for(int i = 1; i <= n; ++i)
		printf("%d ", f[i]);
	return 0;
}