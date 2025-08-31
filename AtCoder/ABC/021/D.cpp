#include <bits/stdc++.h>
using namespace std;
using LL = long long;

constexpr const int P = 1e9 + 7;

LL qpow(LL a, LL b) {
	LL res = 1;
	for(; b; a *= a, a %= P, b >>= 1)
		if(b & 1)
		{ res *= a; res %= P; }
	return res;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, k;
	cin >> n >> k;
	LL tot = 1, fac = 1;
	for(int i = 1; i <= k; ++i) {
		tot *= (n + i - 1); tot %= P;
		fac *= i; fac %= P;
	}
	cout << tot * qpow(fac, P - 2) % P << endl;
	return 0;
}
