#include <iostream>
using namespace std;

constexpr const int P = 1000;
int dp[4][2];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	cin >> n;
	dp[0][0] = 1;
	bool pos = 0;
	for(int k = 1; k < n; ++k) {
		pos = pos ^ true;
		dp[0][pos] = 2 * dp[1][pos ^ true] % P;
		dp[1][pos] = (dp[0][pos ^ true] + dp[2][pos ^ true]) % P;
		dp[2][pos] = (dp[1][pos ^ true] + dp[3][pos ^ true]) % P;
		dp[3][pos] = dp[2][pos ^ true];
	}
	cout << 2 * dp[3][pos] % P << endl;
	return 0;
}
