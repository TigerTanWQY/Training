#include <bits/stdc++.h>
using namespace std;
using LL = long long;

constexpr const int P = 1e9 + 7;
struct Matrix {
	LL a[3][3]{};
	Matrix operator*(const Matrix& b) const {
		Matrix res;
		for(int i = 1; i <= 2; ++i)
			for(int j = 1; j <= 2; ++j)
				for(int k = 1; k <= 2; ++k)
					res.a[i][j] = (res.a[i][j] + a[i][k] * b.a[k][j] % P) % P;
		return res;
	}
	Matrix& operator*=(const Matrix& b) {
		*this = *this * b;
		return *this;
	}
} ans, a;

void qpow(LL b) {
	for(; b; a *= a, b >>= 1)
		if(b & 1)
			ans *= a;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	LL n;
	cin >> n;
	a.a[1][1] = a.a[1][2] = a.a[2][1] = ans.a[1][1] = ans.a[1][2] = 1;
	if(n <= 2) {
		cout.put('1').put('\n');
		return 0;
	}
	qpow(n - 2);
	cout << ans.a[1][1] % P << endl;
	return 0;
}
