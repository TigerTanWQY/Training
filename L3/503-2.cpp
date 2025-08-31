#include <bits/stdc++.h>
using namespace std;

int a[1004], f[1004];

int solve(const int &n)
{
	if(f[n])
		return f[n];
	f[n] = 1;
	for(int i = 1; i < n; ++i)
		if(a[n] > a[i])
			f[n] = max(f[n], solve(i) + 1);
	return f[n];
}

int main()
{
	int n;
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i)
		scanf("%d", &a[i]);
	a[++n] = 1e9 + 1;
	printf("%d", solve(n) - 1);
	return 0;
}