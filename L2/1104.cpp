#include <bits/stdc++.h>
using namespace std;

struct Node
{
	int v;
	Node *next;
} *head = NULL, a[1003];

int main()
{
	int n;
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i)
	{
		scanf("%d", &a[i].v);
		if(head == NULL)
			head = &a[i];
		else
		{
			a[i].next = head;
			head = &a[i];
		}
	}
	for(Node *it = head; it != NULL; it = it->next)
		printf("%d\n", it->v);
	return 0;
}