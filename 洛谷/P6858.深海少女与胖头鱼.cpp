#include <bits/stdc++.h>
using namespace std;
using LL = long long;

constexpr const int P = 998244353;

LL qpow(LL a, LL b) {
	LL res = 1;
	a %= P;
	for(; b; a = a * a % P, b >>= 1)
		if(b & 1)
			res = res * a % P;
	return res;
}
/*
Microsoft.PowerToys
ByteDance.Douyin
Rustlang.Rustup
*/
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	LL n; int m;
	cin >> n >> m; n %= P;
	LL f0 = n * (n + 3) / 2 % P;
	for(int i = 1; i <= m; ++i)
		f0 = (i * (f0 + 1) % P * qpow(n + i, P - 2) % P + n * ((n + i) * (n + i + 3) / 2 % P) % P * qpow(n + i, P - 2) % P) % P;
	cout << f0 << endl;
	return 0;
}
