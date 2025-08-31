#include <iostream>
#include <climits>
#include <algorithm>
using namespace std;
using LL = long long;

const int N = 2003;
LL a[N], dp[N][N]{{0, LLONG_MIN}};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, m;
	cin >> n >> m;
	for(int i = 0; i < n; ++i)
		cin >> a[i];
	for(int i = 1; i <= n; ++i)
		for(int j = 0; j <= n; ++j)
			if(j == 0)
				dp[i][0] = 0;
			else if(j > i)
				dp[i][j] = LLONG_MIN;
			else
				dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - 1] + a[i - 1] * j);
	cout << dp[n][m];
	return 0;
}
