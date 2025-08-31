#include <bits/stdc++.h>
using namespace std;
using LL = long long;

constexpr const int N = 103, P = 1e9 + 7;
int n;
struct Matrix {
	LL a[N][N]{};
	void init()
	{ for(int i = 1; i <= n; ++i) a[i][i] = 1; }
} a;
Matrix operator*(const Matrix& x, const Matrix& y) {
	Matrix res;
	for(int k = 1; k <= n; ++k)
		for(int i = 1; i <= n; ++i)
			for(int j = 1; j <= n; ++j)
				res.a[i][j] = (res.a[i][j] + x.a[i][k] * y.a[k][j] % P) % P;
	return res;
}
Matrix& operator*=(Matrix& x, const Matrix& y) {
	x = x * y;
	return x;
}

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	LL k;
	cin >> n >> k;
	for(int i = 1; i <= n; ++i)
		for(int j = 1; j <= n; ++j)
			cin >> a.a[i][j];
	Matrix ans; ans.init();
	for(; k; a *= a, k >>= 1)
		if(k & 1)
			ans *= a;
	for(int i = 1; i <= n; cout.put('\n'), ++i)
		for(int j = 1; j <= n; cout.put(' '), ++j)
			cout << ans.a[i][j];
	cout.flush();
	return 0;
}
