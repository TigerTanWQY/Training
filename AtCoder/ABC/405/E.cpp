#include <bits/stdc++.h>
using namespace std;
using LL = long long;

const int N = 4e6 + 5, P = 998244353;
LL inv[N], fac[N];

LL qpow(LL a, LL b) {
	LL res = 1;
	for(; b; a = a * a % P, b >>= 1)
		if(b & 1)
			res = res * a % P;
	return res;
}

LL C(int a, int b)
{ return fac[a] * inv[b] % P * inv[a - b] % P; }

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int a, b, c, d;
	cin >> a >> b >> c >> d;
	int tot = a + b + c + d;
	fac[0] = inv[0] = 1;
	for(int i = 1; i <= tot; ++i)
		fac[i] = fac[i - 1] * i % P;
	inv[tot] = qpow(fac[tot], P - 2);
	for(int i = tot - 1; i; --i)
		inv[i] = (i + 1) * inv[i + 1] % P;
	LL ans = 0;
	for(int i = d; i <= c + d; ++i)
		ans = (ans + C(i - 1, d - 1) * C(tot - i, b) % P) % P;
	cout << ans << endl;
	return 0;
}
