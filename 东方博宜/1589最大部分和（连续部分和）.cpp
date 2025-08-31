#include <bits/stdc++.h>
using namespace std;

int x[103], f[103];

int main()
{
	int n;
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i)
		scanf("%d", &x[i]);
	int ans = f[1] = x[1];
	for(int i = 2; i <= n; ++i)
		ans = max(ans, f[i] = max(x[i], f[i - 1] + x[i]));
	printf("%d", ans);
	return 0;
}