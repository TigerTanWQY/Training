#include <bits/stdc++.h>
using namespace std;

int a[100003], c[100003];

int main()
{
	int n, q;
	scanf("%d%d", &n, &q);
	for(int i = 1; i <= n; ++i)
		scanf("%d", &a[i]);
	for(int i = 1; i <= n; ++i)
		c[i] = a[i] - a[i - 1];
	while(q--)
	{
		int l, r;
		scanf("%d%d", &l, &r);
		++c[l];
		--c[r + 1];
	}
	for(int i = 1; i <= n; ++i)
	{
		c[i] += c[i - 1];
		printf("%d ", c[i]);
	}
	return 0;
}