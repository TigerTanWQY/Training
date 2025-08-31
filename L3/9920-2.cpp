#include <bits/stdc++.h>
using namespace std;

const int N = 201000;
int t[N], dp[N], s1[N], s2[N], cnt[N];

int main()
{
	int n, m;
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; ++i)
	{
		scanf("%d", &t[i]);
		++t[i];
	}
	sort(t + 1, t + n + 1);
	for(int i = 1; i <= n; ++i)
		if(t[i] - t[i - 1] >= 2 * m)
		{
			int c = t[i] - t[i - 1] - 2 * m;
			for(int j = i; j <= n; ++j)
				t[j] -= c;
		}
	int T = t[n] + m;
	for(int i = 1; i <= n; ++i)
		++cnt[t[i]];
	for(int i = 1; i <= T; ++i)
	{
		s1[i] = s1[i - 1] + cnt[i];
		s2[i] = s2[i - 1] + cnt[i] * i;
	}
	int ans = INT_MAX;
	for(int i = 1; i <= T; ++i)
	{
		dp[i] = i * s1[i] - s2[i];
		for(int j = i - m; j >= 1 && j >= i - 2 * m + 1; --j)
			dp[i] = min(dp[i], dp[j] + i * (s1[i] - s1[j]) - (s2[i] - s2[j]));
		if(i >= t[n])
			ans = min(ans, dp[i]);
	}
	printf("%d", ans);
	return 0;
}