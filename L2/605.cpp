#include <bits/stdc++.h>
using namespace std;

const int MOD = 10007;
int num[100003], col[100003];
int a1[100003][2], a2[100003][2], a3[100003][2], a4[100003][2];

int main()
{
	int n, m;
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; ++i)
		scanf("%d", &num[i]);
	for(int i = 1; i <= n; ++i)
		scanf("%d", &col[i]);
	int ans = 0;
	for(int i = 1; i <= n; ++i)
	{
		int y = i % 2;
		ans += a1[col[i]][y];
		ans %= MOD;
		ans += a2[col[i]][y] * num[i];
		ans %= MOD;
		ans += a3[col[i]][y] * i;
		ans %= MOD;
		ans += a4[col[i]][y] * i % MOD * num[i] % MOD;
		ans %= MOD;
		a1[col[i]][y] += 1LL * i * num[i] % MOD;
		a1[col[i]][y] %= MOD;
		a2[col[i]][y] += i;
		a2[col[i]][y] %= MOD;
		a3[col[i]][y] += num[i];
		a3[col[i]][y] %= MOD;
		++a4[col[i]][y];
		a4[col[i]][y] %= MOD;
	}
	printf("%d", ans);
	return 0;
}