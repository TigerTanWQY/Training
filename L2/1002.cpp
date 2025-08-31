#include <bits/stdc++.h>
using namespace std;

int a[100003], c[100003], r[100003];

bool cmp(const int& x, const int& y)
{
	if(a[x] != a[y])
		return a[x] < a[y];
	return x < y;
}

int main()
{
	int n;
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i)
	{
		scanf("%d", &a[i]);
		c[i] = i;
	}
	sort(c + 1, c + n + 1, cmp);
	for(int i = 1; i <= n; ++i)
		printf("%d ", a[c[i]]);
	printf("\n");
	for(int i = 1; i <= n; ++i)
		r[c[i]] = i;
	for(int i = 1; i <= n; ++i)
		printf("%d ", r[i]);
	return 0;
}