#include <bits/stdc++.h>
using namespace std;

const int MOD = 55555;
//因此他会在1~N的每个座位放最多 1 个苹果，
//!他不会在连续 3 个座位上都放苹果。
int main()
{
	int n;
	scanf("%d", &n);
	int ans = 1;
	for(int _ = 1; _ <= n; ++_)
		ans = ans * 2 % MOD;
	ans -= (n - 2 + 1) * (n - 2) / 2;
	while(ans < 0)
		ans += MOD;
	printf("%d", ans);
	return 0;
}