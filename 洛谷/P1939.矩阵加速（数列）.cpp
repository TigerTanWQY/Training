#include <bits/stdc++.h>
using namespace std;
using LL = long long;

constexpr const int P = 1e9 + 7;
struct Matrix
{ LL a[5][5]{}; }
ans, a;

Matrix operator*(const Matrix& A, const Matrix& B) {
	Matrix res;
	for(int i = 1; i <= 3; ++i)
		for(int j = 1; j <= 3; ++j)
			for(int k = 1; k <= 3; ++k) {
				res.a[i][j] += A.a[i][k] * B.a[k][j] % P;
				res.a[i][j] %= P;
			}
	return res;
}

Matrix& operator*=(Matrix& A, const Matrix& B) {
	A = A * B;
	return A;
}

void init() {
	memset(ans.a, 0, sizeof(ans.a));
	for(int i = 1; i <= 3; ++i)
		ans.a[i][i] = 1;
	memset(a.a, 0, sizeof(a.a));
	a.a[1][1] = a.a[1][3] = a.a[2][1] = a.a[3][2] = 1;
}

void qpow(int k) {
	for(; k; a *= a, k >>= 1)
		if(k & 1)
			ans *= a;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int _T;
	cin >> _T;
	for(int n; _T--; cout.put('\n')) {
		cin >> n;
		if(n <= 3) {
			cout.put('1');
			continue;
		}
		init();
		qpow(n);
		cout << ans.a[2][1];
	}
	cout.flush(); return 0;
}
