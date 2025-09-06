#include <bits/stdc++.h>
using namespace std;
using LL = long long;

constexpr const int b[]{0, 2, 3, 4679, 35617};
constexpr const int P = 999911658;
LL f[50003], a[5];

LL qpow(LL a, LL b, const int p) {
	LL res = 1;
	for(; b; b >>= 1, a = a * a % p)
		if(b & 1)
			res = res * a % p;
	return res;
}

LL C(LL n, LL m, const int p)
{ return (n < m? 0: f[n] * qpow(f[m], p - 2, p) % p * qpow(f[n - m], p - 2, p) % p); }

LL Lucas(LL n, LL m, const int p) {
	if(n < m)
		return 0;
	else if(!n)
		return 1;
	else
		return Lucas(n / p, m / p, p) * C(n % p, m % p, p) % p;
}

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int n, G;
	cin >> n >> G;
	if(!(G % (P + 1))) {
		cout.put('0') << endl;
		return 0;
	}
	for(int k = 1; k < 5; ++k) {
		f[0] = 1;
		for(int i = 1; i <= b[k]; ++i)
			f[i] = 1LL * f[i - 1] * i % b[k];
		for(int i = 1; i * i <= n; ++i)
			if(!(n % i)) {
				a[k] = (a[k] + Lucas(n, i, b[k])) % b[k];
				if(i * i != n)
					a[k] = (a[k] + Lucas(n, n / i, b[k])) % b[k];
			}
 	}
 	LL w = 0;
 	for(int i = 1; i < 5; ++i)
		w = (w + a[i] * (P / b[i]) % P * qpow(P / b[i], b[i] - 2, b[i])) % P;
	cout << qpow(G, w, P + 1) << endl;
	return 0;
}
