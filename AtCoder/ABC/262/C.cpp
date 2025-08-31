#include <bits/stdc++.h>
using namespace std;

int a[500003];

int main()
{
	int n;
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i)
		scanf("%d", &a[i]);
	long long x = 0, y = 0;
	for(int i = 1; i <= n; ++i)
		if(i == a[i])
			++x;
		else if(a[a[i]] == i)
			++y;
	printf("%lld", x * (x - 1) / 2 + y / 2);
	return 0;
}