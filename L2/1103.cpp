#include <bits/stdc++.h>
using namespace std;

struct Node
{
	int v;
	Node *next;
} *h1, *t1, *h2, *t2, a[100003], b[100003];

Node *Merge(Node *h1, Node *h2)
{
	Node *h3 = NULL, *t3 = NULL;
	while(h1 != NULL && h2 != NULL)
	{
		if(h1->v < h2->v)
		{
			if(h3 == NULL)
				h3 = t3 = h1;
			else
			{
				t3->next = h1;
				t3 = h1;
			}
			Node *x = h1;
			h1 = h1->next;
			x->next = NULL;
		}
		else
		{
			if(h3 == NULL)
				h3 = t3 = h2;
			else
			{
				t3->next = h2;
				t3 = h2;
			}
			Node *x = h2;
			h2 = h2->next;
			x->next = NULL;
		}
	}
	while(h1 != NULL)
	{
		t3->next = h1;
		t3 = h1;
		Node *x = h1;
		h1 = h1->next;
		x->next = NULL;
	}
	while(h2 != NULL)
	{
		t3->next = h2;
		t3 = h2;
		Node *x = h2;
		h2 = h2->next;
		x->next = NULL;
	}
	return h3;
}

int main()
{
	int n, m;
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; ++i)
	{
		scanf("%d", &a[i].v);
		if(h1 == NULL)
			h1 = t1 = &a[i];
		else
		{
			t1->next = &a[i];
			t1 = &a[i];
		}
	}
	for(int i = 1; i <= m; ++i)
	{
		scanf("%d", &b[i].v);
		if(h2 == NULL)
			h2 = t2 = &b[i];
		else
		{
			t2->next = &b[i];
			t2 = &b[i];
		}
	}
	Node *h3 = Merge(h1, h2);
	for(Node *it = h3; it != NULL; it = it->next)
		printf("%d ", it->v);
	return 0;
}