#include <bits/stdc++.h>
using namespace std;
using LL = long long;

constexpr const int P = 1e9 + 7, N = 353;
LL C[N][N], ans[N][N];

LL qpow(LL a, LL b) {
	LL res = 1;
	for(; b; a = a * a % P, b >>= 1)
		if(b & 1)
			res = res * a % P;
	return res;
}

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int n;
	cin >> n;
	for(int i = 0; i <= n; ++i) {
		C[i][0] = C[i][i] = 1;
		for(int j = 1; j < i; ++j)
			C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % P;
	}
	ans[1][1] = 1;
	for(int i = 2; i <= n; ++i)
		for(int j = 1; j <= n; ++j) {
			if(j >= i)
				ans[i][j] = 1LL * C[j][i] * qpow(i - 1, j - i) % P;
			for(int k = 0; k <= j; ++k)
				if(i != k)
					ans[i][j] = (ans[i][j] + 1LL * ans[i - 1][j - k] * C[j][k]) % P;
		}
	cout << ans[n][n] << endl;
	return 0;
}
