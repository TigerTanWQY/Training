#include <bits/stdc++.h>
using namespace std;
using LL = long long;

const int N = 203;
LL x[N], y[N], p[N], dp[N][N];

inline LL f(const LL &a, const LL &b)
{
	if(a % b)
		return a / b + 1;
	else
		return a / b;
}

int main()
{
	int n;
	scanf("%d", &n);
	for(int i = 0; i < n; ++i)
		scanf("%lld%lld%lld", &x[i], &y[i], &p[i]);
	for(int i = 0; i < n; ++i)
		for(int j = 0; j < n; ++j)
			dp[i][j] = f(abs(x[i] - x[j]) + abs(y[i] - y[j]), p[i]);
	for(int k = 0; k < n; ++k)
		for(int i = 0; i < n; ++i)
			for(int j = 0; j < n; ++j)
				dp[i][j] = min(dp[i][j], max(dp[i][k], dp[k][j]));
	LL s = LLONG_MAX;
	for(int i = 0; i < n; ++i)
	{
		LL m = 0;
		for(int j = 0; j < n; ++j)
			m = max(m, dp[i][j]);
		s = min(s, m);
	}
	printf("%lld", s);
	return 0;
}