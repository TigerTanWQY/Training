#include <iostream>
using namespace std;

const int P = 1e9 + 7;
const int N = 200003;
int fac[N];

int qpow(int a, int b) {
	int res = 1;
	for(; b; a = 1LL * a * a % P, b /= 2)
		if(b & 1)
			res = 1LL * res * a % P;
	return res;
}

int C(const int& n, const int& m) {
	int res = 1;
	for(int i = 1, j = n; i <= m; ++i, --j)
		res = 1LL * res * j % P * qpow(i, P - 2) % P;
	return res;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	cin >> n;
	fac[0] = 1;
	for(int i = 1; i < N; ++i)
		fac[i] = 1LL * fac[i - 1] * i % P;
	cout << 1LL * C(2 * n, n) * qpow(n + 1, P - 2) % P;
	cout.flush();
	return 0;
}