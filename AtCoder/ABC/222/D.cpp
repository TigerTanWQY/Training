#include <iostream>
#include <atcoder/modint>
using namespace std;
using mint = atcoder::modint998244353;

constexpr const int V = 3'000, N = V + 3;
mint dp[N][N];
int a[N], b[N];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	cin >> n;
	for(int i = 0; i < n; ++i)
		cin >> a[i];
	for(int i = 0; i < n; ++i)
		cin >> b[i];
	dp[0][0] = 1;
	for(int i = 0; i <= n; ++i) {
		for(int j = 0; j <= V; ++j)
			dp[i][j + 1] += dp[i][j];
		if(i != n)
			for(int j = a[i]; j <= b[i]; ++j)
				dp[i + 1][j] += dp[i][j];
	}
	cout << dp[n][V].val() << endl;
	return 0;
}