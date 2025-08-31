#include <iostream>
#include <cstring>
using namespace std;
using LL = long long;

constexpr const int P = 1e9 + 7;
struct Matrix {
	LL M[53][53];
	int sz;
	Matrix()
	: sz(0)
	{ memset(M, 0, sizeof(M)); }
	Matrix friend operator*(const Matrix& A, const Matrix& b) {
		Matrix res;
		res.sz = A.sz;
		for(int i = 1; i <= res.sz; ++i)
			for(int k = 1; k <= res.sz; ++k)
				for(int j = 1; j <= res.sz; ++j) {
					res.M[i][j] += A.M[i][k] * b.M[k][j] % P;
					res.M[i][j] %= P;
				}
		return res;
	}
} A;

Matrix qpow(Matrix a, LL b) {
	Matrix res;
	res.sz = a.sz;
	for(int i = 1; i <= a.sz; ++i)
		res.M[i][i] = 1;
	for(; b; a = a * a, b >>= 1)
		if(b & 1)
			res = res * a;
	return res;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	LL k;
	cin >> n >> k;
	A.sz = n;
	for(int i = 1; i <= n; ++i)
		for(int j = 1; j <= n; ++j)
			cin >> A.M[i][j];
	LL ans = 0;
	Matrix res = qpow(A, k);
	for(int i = 1; i <= n; ++i)
		for(int j = 1; j <= n; ++j) {
			ans += res.M[i][j];
			ans %= P;
		}
	cout << ans << endl;
	return 0;
}