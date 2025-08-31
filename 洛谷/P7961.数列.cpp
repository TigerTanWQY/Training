#include <iostream>
using namespace std;
using LL = long long;

constexpr const LL P = 998'244'353, M = 103, N = 33;
int v[M];
LL dp[M][N][N][N / 2 + 3], sv[M][N], C[N][N];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	C[0][0] = 1;
	for(int i = 1; i < N; ++i) {
		C[i][0] = 1;
		for(int j = 1; j <= i; ++j)
			C[i][j] = (C[i - 1][j] + C[i - 1][j - 1]) % P;
	}
	int n, m, K;
	cin >> n >> m >> K;
	for(int i = 0; i <= m; ++i) {
		cin >> v[i];
		sv[i][0] = 1;
		for(int j = 1; j <= n; ++j)
			sv[i][j] = sv[i][j - 1] * v[i] % P;
	}
	dp[0][0][0][0] = 1;
	for(int i = 0; i <= m; ++i)
		for(int j = 0; j <= n; ++j)
			for(int k = 0; k <= K; ++k)
				for(int x = 0; x <= n >> 1; ++x)
					for(int y = 0; y <= n - j; ++y)
						dp[i + 1][j + y][k + (y + x & 1)][(y + x) / 2] = (dp[i + 1][j + y][k + (y + x & 1)][(y + x) / 2] + dp[i][j][k][x] * sv[i][y] % P * C[n - j][y] % P) % P;
	LL ans = 0;
	for(int k = 0; k <= K; ++k)
		for(int x = 0; x <= n >> 1; ++x)
			if(k + __builtin_popcountll(x) <= K)
				ans = (ans + dp[m + 1][n][k][x]) % P;
	cout << ans << endl;
	return 0;
}