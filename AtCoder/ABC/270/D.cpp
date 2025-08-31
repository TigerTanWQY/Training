#include <iostream>
using namespace std;

int a[103], dp[10003];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, k;
	cin >> n >> k;
	for(int i = 0; i < k; ++i)
		cin >> a[i];
	for(int i = 0; i <= n; ++i)
		for(int j = 0; j < k; ++j)
			if(a[j] <= i)
				dp[i] = max(dp[i], i - dp[i - a[j]]);
	cout << dp[n];
	return 0;
}
