#include <bits/stdc++.h>
using namespace std;

int a[100003];

void qsort(const int &l, const int &r)
{
	if(l >= r)
		return;
	swap(a[l], a[l + rand() % (r - l + 1)]);
	int x = a[l];
	int i = l, j = r;
	while(i < j)
	{
		while(i < j && a[j] > x)
			--j;
		if(i < j)
			a[i++] = a[j];
		while(i < j && a[i] < x)
			++i;
		if(i < j)
			a[j--] = a[i];
	}
	a[i] = x;
	qsort(l, i - 1);
	qsort(i + 1, r);
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