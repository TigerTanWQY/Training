#include <bits/stdc++.h>
using namespace std;

struct Node
{
	int v;
	Node *prev, *next;
} a[103];

int main()
{
	int n, m;
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; ++i)
	{
		a[i].v = i;
		if(i == 1)
			a[i].prev = &a[n];
		else
			a[i].prev = &a[i - 1];
		if(i == n)
			a[i].next = &a[1];
		else
			a[i].next = &a[i + 1];
	}
	Node *p = &a[n];
	int cnt = 0;
	while(true)
	{
		p = p->next;
		if(++cnt == m)
		{
			printf("%d ", p->v);
			if(p->next == p)
				break;
			else
			{
				Node *l = p->prev, *r = p->next;
				l->next = r;
				r->prev = l;
				p->prev = p->next = NULL;
				cnt = 0;
				p = l;
			}
		}
	}
	return 0;
}