#include <bits/stdc++.h>
using namespace std;

const int MOD = 997;
int a[100003], f[100003];

int main()
{
	int n, x;
	scanf("%d%d", &n, &x);
	a[1] = f[1] = x;
	int ans = x;
	for(int i = 2; i <= n; ++i)
	{
		a[i] = (379 * a[i - 1] + 131) % MOD;
		ans += (f[i] = max(f[i - 1], a[i]));
	}
	printf("%d", ans);
	return 0;
}