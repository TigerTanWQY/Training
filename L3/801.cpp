#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

int main()
{
	int n, m;
	scanf("%d%d", &n, &m);
	long long ans = 1LL;
	for(int i = n; i >= n - m + 1; --i)
		ans = ans * i % MOD;
	printf("%lld", ans);
	return 0;
}