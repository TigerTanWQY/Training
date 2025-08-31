#include <bits/stdc++.h>
using namespace std;

long long a[100003];

int main()
{
	int n, m;
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; ++i)
	{
		int x;
		scanf("%d", &x);
		a[i] = a[i - 1] + x;
	}
	while(m--)
	{
		int l, r;
		scanf("%d%d", &l, &r);
		printf("%lld\n", a[r] - a[l - 1]);
	}
	return 0;
}