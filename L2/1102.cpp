#include <bits/stdc++.h>
using namespace std;

struct Node
{
	int v;
	Node *next;
} *head = NULL, *tail = NULL, a[100003];

int main()
{
	int n;
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i)
	{
		scanf("%d", &a[i].v);
		if(head == NULL)
			head = tail = &a[i];
		else
		{
			tail->next = &a[i];
			tail = &a[i];
		}
	}
	Node *p1 = head;
	for(Node *p2 = head; p2->next->next != NULL; p1 = p1->next, p2 = p2->next->next);
	printf("%d", p1->v);
	return 0;
}