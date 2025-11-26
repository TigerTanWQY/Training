#include <bits/stdc++.h>
using namespace std;

constexpr const int N = 2e5 + 3;
int t[N], dp[N], s1[N], s2[N], cnt[N];

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	for(int i = 1; i <= n; ++i) {
		cin >> t[i];
		++t[i];
	}
	sort(t+1, t+n+1);
	for(int i = 1; i <= n; ++i)
		if(t[i] - t[i-1] >= 2 * m) {
			int c = t[i] - t[i-1] - 2*m;
			for(int j = i; j <= n; ++j)
				t[j] -= c;
		}
	int T = t[n] + m;
	for(int i = 1; i <= n; ++i)
		++cnt[t[i]];
	for(int i = 1; i <= T; ++i) {
		s1[i] = s1[i-1] + cnt[i];
		s2[i] = s2[i-1] + cnt[i]*i;
	}
	int ans = 0x3f3f3f3f;
	for(int i = 1; i <= T; ++i) {
		dp[i] = i*s1[i] - s2[i];
		for(int j = i-m; j >= 1 && j >= i-2*m+1; --j)
			dp[i] = min(dp[i], dp[j] + i * (s1[i]-s1[j]) - (s2[i]-s2[j]));
		if(i >= t[n])
			ans = min(ans, dp[i]);
	}
	cout << ans << endl;
	return 0;
}
