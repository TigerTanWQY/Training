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

LL C(int n, int m) {
	LL a = 1, b = 1;
	for(int i = n; i >= n - m + 1; --i)
	{ a *= i; a %= P; }
	for(int i = m; i; --i)
	{ b *= i; b %= P; }
	return a * qpow(b, P - 2) % P;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, m;
	cin >> n >> m;
	cout << C(n + m - 2, n - 1) << endl;
	return 0;
}
