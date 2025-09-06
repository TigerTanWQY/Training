#include <bits/stdc++.h>
using namespace std;
using LL = long long;

unordered_map<LL, LL> mp;
LL p;

LL qpow(LL a, LL k) {
	LL res = 1; a %= p;
	for(; k; k >>= 1, a = a * a % p)
		if(k & 1)
			res = res * a % p;
	return res;
}

LL bsgs(LL a, LL b) {
	if(a % p == 0)
		return -1;
	mp.clear();
	LL m = ceil(sqrt(p)), am = qpow(a, m);
	for(int j = 0; j <= m; ++j)
	{ mp[b] = j; b = b * a % p;}
	LL mul = 1;
	for(int i = 1; i <= m; ++i) {
		mul = mul * am % p;
		if(mp[mul])
			return i * m - mp[mul] + 1;
	}
	return -1;
}

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int _T;
	cin >> _T;
	for(LL a, b, x1, xn; _T--; cout.put('\n')) {
		cin >> p >> a >> b >> x1 >> xn;
		if(x1 == xn)
			cout.put('1');
		else if(a == 0)
			cout << (xn == b? "2": "-1");
		else if(a == 1 && b == 0)
			cout << "-1";
		else if(a == 1)
			cout << ((((xn - x1) % p + p) % p) * qpow(b, p - 2) % p) % p + 1;
		else {
			LL inv = b % p * qpow(a - 1, p - 2) % p;
			cout << bsgs(a, (xn % p + inv) % p * qpow((x1 % p + inv) % p, p - 2) % p);
		}
	}
	cout.flush(); return 0;
}
