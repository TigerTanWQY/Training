#include <bits/stdc++.h>
using namespace std;

struct Node
{
	int s;
	Node *next;
} *head = NULL, a[83];

int main()
{
	int n;
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i)
	{
		scanf("%d", &a[i].s);
		if(head == NULL)
			head = &a[i];
		else if(a[i].s < head->s)
		{
			a[i].next = head;
			head = &a[i];
		}
		else
		{
			Node *p = head;
			for(Node *it = head; it != NULL; it = it->next)
			{
				if(a[i].s > it->s)
					p = it;
				else
					break;
			}
			a[i].next = p->next;
			p->next = &a[i];
		}
	}
	for(Node *it = head; it != NULL; it = it->next)
		printf("%d ", it->s);
	return 0;
}