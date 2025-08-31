#include <bits/stdc++.h>
using namespace std;

int a[100003], b[100003], c[100003];

void qsort(const int &l, const int &r)
{
	if(l >= r)
		return;
	int x = a[l + rand() % (r - l + 1)];
	int l1 = 0, l2 = 0, y = 0;
	for(int i = l; i <= r; ++i)
		if(a[i] < x)
			b[++l1] = a[i];
		else if(a[i] > x)
			c[++l2] = a[i];
		else
			++y;
	int p = l;
	for(int i = 1; i <= l1; ++i)
		a[p++] = b[i];
	for(int i = 1; i <= y; ++i)
		a[p++] = x;
	for(int i = 1; i <= l2; ++i)
		a[p++] = c[i];
	qsort(l, l + l1 - 1);
	qsort(l + l1 + y, r);
}

int main()
{
	srand(time(NULL));
	int n;
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i)
		scanf("%d", &a[i]);
	qsort(1, n);
	for(int i = 1; i <= n; ++i)
		printf("%d ", a[i]);
	return 0;
}