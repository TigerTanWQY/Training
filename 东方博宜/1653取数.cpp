#include <bits/stdc++.h>
using namespace std;

int a[53], f[103];

int main()
{
	int n;
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i)
		scanf("%d", &a[i]);
	f[2] = max(f[1] = a[1], a[2]);
	for(int i = 3; i <= n; ++i)
		f[i] = max(f[i - 1], a[i] + f[i - 2]);
	printf("%d", f[n]);
	return 0;
}