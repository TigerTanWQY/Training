#include <bits/stdc++.h>
using namespace std;
using LL = long long;

constexpr const int P = 1e9 + 7, N = 3e6 + 3;
LL fac[N], inv[N];

LL qpow(LL a, LL b) {
	LL res = 1;
	for(; b; a = a * a % P, b >>= 1)
		if(b & 1)
			res = res * a % P;
	return res;
}

LL C(int n, int k) {
	if(k < 0 || k > n)
		return 0;
	return fac[n] * inv[k] % P * inv[n - k] % P;
}

LL calc(int m, int s, int M) {
	if(m == 0)
		return s == 0;
	if(s < 0)
		return 0;
	LL res = C(s + m - 1, m - 1);
	if(M < 0)
		return res;
	for(int k = 1; k <= m && s >= k * (M + 1); ++k) {
		LL term = C(m, k) * C(s - k * (M + 1) + m - 1, m - 1) % P;
		if(k & 1)
			res = (res - term + P) % P;
		else
			res = (res + term) % P;
	}
	return res;
}

int main() {
	freopen("ring.in", "r", stdin);
	freopen("ring.out", "w", stdout);
	cin.tie(nullptr)->sync_with_stdio(false);
	fac[0] = 1;
	for(int i = 1; i < N; ++i)
		fac[i] = fac[i - 1] * i % P;
	inv[N - 1] = qpow(fac[N - 1], P - 2);
	for(int i = N - 2; i >= 0; --i)
		inv[i] = inv[i + 1] * (i + 1) % P;
	int _T;
	cin >> _T;
	for(int r, g, b, p, q; _T--; cout.put('\n')) {
		cin >> r >> g >> b >> p >> q;
		if(r == 0)
			if(g == 0)
				if(b > 0)
					cout << (b == 1? 1: fac[b - 1] % P);
				else
					cout.put('1');
			else {
				if(b < g * q) {
					cout.put('0');
					continue;
				}
				int S = b - g * q, M = b - 2 * q,
					res = calc(g, S, M);
				if(res == 0)
					cout.put('0');
				else
					cout << fac[g - 1] * fac[b] % P * res % P;
			}
		else if(g == 0)
			if(r > 0 && p > 0)
				cout.put('0');
			else
				if(r == 0)
					if(b == 0)
						cout.put('1');
					else
						cout << (b == 1? 1: fac[b - 1] % P);
				else
					if(r == 1 && b == 0)
						cout.put('1');
					else
						cout << fac[r + b - 1] % P;
		else if(b == 0) {
			if(q != 0) {
				cout.put('0');
				continue;
			}
			if(r == 0)
				cout << (g == 1? 1: fac[g - 1]);
			else if(r == 1)
				cout << fac[g] % P;
			else {
				int S = g - r * p;
				if(g < r * p) {
					cout.put('0');
					continue;
				}
				if(g < 2 * p && p > 0) {
					cout.put('0');
					continue;
				}
				int res = calc(r, S, g - 2 * p);
				if(res == 0) {
					cout.put('0');
					continue;
				}
				cout << fac[r - 1] * res % P * fac[g] % P;
			}
		}
	}
	cout.flush(); return 0;
}
