#include <iostream>
#include <cstring>
using namespace std;
using LL = long long;

const int MAXN = 103;
int a[MAXN];
LL dp[MAXN][MAXN][MAXN];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int N, K, D;
	cin >> N >> K >> D;
	for(int i = 0; i < N; ++i)
		cin >> a[i];
	memset(dp, -1, sizeof(dp));
	dp[0][0][0] = 0;
	for(int i = 0; i < N; ++i)
		for(int j = 0; j <= K; ++j)
			for(int k = 0; k < D; ++k)
				if(dp[i][j][k] != -1) {
					dp[i + 1][j][k] = max(dp[i + 1][j][k], dp[i][j][k]);
					if(j != K)
						dp[i + 1][j + 1][(k + a[i]) % D] = max(dp[i + 1][j + 1][(k + a[i]) % D], dp[i][j][k] + a[i]);
				}
	cout << dp[N][K][0];
	return 0;
}