#include <bits/stdc++.h>
using namespace std;

int a[100003], r[100003], g[100003];

int main()
{
	int n, m;
	scanf("%d%d", &n, &m);
	for(int i = 1; i < n; ++i)
		scanf("%d", &a[i]);
	for(int i = 1; i <= n; ++i)
		scanf("%d", &r[i]);
	for(int i = 1; i <= n; ++i)
		scanf("%d", &g[i]);
	return 0;
}