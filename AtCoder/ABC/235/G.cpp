#include <iostream>
using namespace std;
#define int long long

const int P = 998244353;
const int N = 5000000;
int fac[N + 3], inv[N + 3];

int fpow(int a, int b, const int& p) {
	int res = 1;
	while(b) {
		if(b & 1)
			res = res * a % p;
		b >>= 1;
		a = a * a % p;
	}
	return res;
}

int C(const int& n, const int& r) {
	if(n < 0 || r < 0 || n < r)
		return 0;
	return fac[n] * inv[r] % P * inv[n - r] % P;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	fac[0] = 1;
	for(int i = 1; i <= N; ++i)
		fac[i] = fac[i - 1] * i % P;
	inv[N] = fpow(fac[N], P - 2, P);
	for(int i = N - 1; i >= 0; --i)
		inv[i] = inv[i + 1] * (i + 1) % P;
	int n, a, b, c, ans = 0, ta = 1, tb = 1, tc = 1, sgn = 1;
	cin >> n >> a >> b >> c;
	if(n % 2)
		sgn = -1;
	for(int i = 0; i <= n; ++i) {
		int cur = C(n, i) * ta % P * tb % P * tc % P;
		ans = (ans + cur * sgn) % P;
		ta = (2 * ta - C(i, a)) % P;
		tb = (2 * tb - C(i, b)) % P;
		tc = (2 * tc - C(i, c)) % P;
		sgn = -sgn;
	}
	cout << ans;
	return 0;
}