#include <iostream>
using namespace std;

int qpow(int a, int b, const int p) {
	int res = 1;
	while(b) {
		if(b & 1)
			res = 1LL * res * a % p;
		a = 1LL * a * a % p;
		b >>= 1;
	}
	return res;
}

int C(const int n, const int m, const int p) {
	int res = 1;
	for(int i = 1, j = n; i <= m; ++i, --j)
		res = 1LL * res * j % p * qpow(i, p - 2, p) % p;
	return res;
}

int Lucas(const int n, const int m, const int p) {
	if(n < p && m < p)
		return C(n, m, p);
	else
		return 1LL * C(n % p, m % p, p) * Lucas(n / p, m / p, p) % p;
}

int main () {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int _T;
	cin >> _T;
	for(int n, m, p; _T--; ) {
		cin >> n >> m >> p;
		cout << Lucas(n + m, m, p) << '\n';
	}
	cout.flush();
	return 0;
}