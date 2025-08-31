#include <bits/stdc++.h>
using namespace std;

int a[100003], f[100003];

int main()
{
	int n, x;
	scanf("%d%d", &n, &x);
	int ans = f[1] = a[1] = x;
	for(int i = 2; i <= n; ++i)
	{
		a[i] = (379 * a[i - 1] + 131) % 997;
		ans += (f[i] = min(f[i - 1], a[i]));
	}
	printf("%d", ans);
	return 0;
}