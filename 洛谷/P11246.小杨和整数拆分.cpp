#include <bits/stdc++.h>
using namespace std;

int dp[100003];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	cin >> n;
	for(int i = 0; i <= n; ++i)
		dp[i] = i;
	for(int i = 1; i <= n; ++i)
		for(int j = 1; j * j <= i; ++j)
			dp[i] = min(dp[i], dp[i - j * j] + 1);
	cout << dp[n] << endl;
	return 0;
}
