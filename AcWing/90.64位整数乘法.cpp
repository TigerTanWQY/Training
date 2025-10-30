#include <bits/stdc++.h>
using namespace std;
using LL = long long;

LL qpow(LL a, LL b, LL p) {
	a %= p;
	LL res = 0;
	for(; b; a = a * 2 % p, b >>= 1)
		if(b & 1)
			res = (res + a) % p;
	return res;
}

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	LL a, b, p;
	cin >> a >> b >> p;
	cout << qpow(a, b, p) << endl;
	return 0;
}
