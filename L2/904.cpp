#include <bits/stdc++.h>
using namespace std;

int a[1003], q[1000003], ans[1003];
int f = 1, r = 0;

int main()
{
	int n;
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i)
		scanf("%d", &a[i]);
	for(int i = 1; i <= n; ++i)
		q[++r] = i;
	for(int t = 1; r >= f; ++t)
	{
		int x = q[f];
		++f;
		--a[x];
		if(a[x] == 0)
			ans[x] = t;
		else
			q[++r] = x;
	}
	for(int i = 1; i <= n; ++i)
		printf("%d ", ans[i]);
	return 0;
}