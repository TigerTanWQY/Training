#include <bits/stdc++.h>
using namespace std;

struct Node
{
	int v, p;
	bool operator<(const Node& x) const
	{
		if(v != x.v)
			return v < x.v;
		return p < x.p;
	}
} c[100003];
int a[100003], r[100003];

int main()
{
	int n;
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i)
	{
		scanf("%d", &a[i]);
		c[i].v = a[i];
		c[i].p = i;
	}
	sort(c + 1, c + n + 1);
	for(int i = 1; i <= n; ++i)
		printf("%d ", a[c[i].p]);
	printf("\n");
	for(int i = 1; i <= n; ++i)
		r[c[i].p] = i;
	for(int i = 1; i <= n; ++i)
		printf("%d ", r[i]);
	return 0;
}