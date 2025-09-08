#include <bits/stdc++.h>
using namespace std;
using LL = long long;

int phi(int x) {
	int res = x;
	for(int i = 2; i * i <= x; ++i)
		if(x % i == 0) {
			res = res / i * (i - 1);
			do
				x /= i;
			while(x % i == 0);
		}
	if(x > 1)
		res = res / x * (x - 1);
	return res;
}

LL qpow(LL x, LL y, LL p) {
	LL res = 1;
	for(; y; x *= x, x %= p, y >>= 1)
		if(y & 1)
			res = res * x % p;
	return res;
}

int f(int x) {
	if(x < 3)
		return 0;
	int n = phi(x);
	return qpow(2, n + f(n), x);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int _T;
	cin >> _T;
    for(int x; _T--; cout.put('\n')) {
		cin >> x;
		cout << f(x);
    }
    cout.flush();
    return 0;
}
