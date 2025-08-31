#include <bits/stdc++.h>
using namespace std;

int a[100003], c[100003];

void msort(const int &l, const int &r)
{
	if(l == r)
		return;
	int m = (l + r) / 2;
	msort(l, m);
	msort(m + 1, r);
	int p1 = l, p2 = m + 1, tot = 0;
	while(p1 <= m && p2 <= r)
		if(a[p1] <= a[p2])
			c[++tot] = a[p1++];
		else
			c[++tot] = a[p2++];
	while(p1 <= m)
		c[++tot] = a[p1++];
	while(p2 <= r)
		c[++tot] = a[p2++];
	for(int i = 1; i <= tot; ++i)
		a[l + i - 1] = c[i];
}

int main()
{
	int n;
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i)
		scanf("%d", &a[i]);
	msort(1, n);
	for(int i = 1; i <= n; ++i)
		printf("%d ", a[i]);
	return 0;
}