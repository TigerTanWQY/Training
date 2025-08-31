#include <bits/stdc++.h>
using namespace std;

int n, t[2051];

void makeTree(const int &i)
{
	if(i > n)
		return;
	t[i] = i;
	makeTree(i + i);
	makeTree(i + i + 1);
}

void preOrder(const int &p)
{
	printf("%d ", t[p]);
	if(t[p + p])
		preOrder(t[p + p]);
	if(t[p + p + 1])
		preOrder(t[p + p + 1]);
}

void inOrder(const int &p)
{
	if(t[p + p])
		inOrder(t[p + p]);
	printf("%d ", t[p]);
	if(t[p + p + 1])
		inOrder(t[p + p + 1]);
}

void postOrder(const int &p)
{
	if(t[p + p])
		postOrder(t[p + p]);
	if(t[p + p + 1])
		postOrder(t[p + p + 1]);
	printf("%d ", t[p]);
}

int main()
{
	scanf("%d", &n);
	int root = 1;
	makeTree(root);
	preOrder(root);
	printf("\n");
	inOrder(root);
	printf("\n");
	postOrder(root);
	return 0;
}