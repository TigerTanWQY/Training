#include <bits/stdc++.h>
using namespace std;
using LL = long long;

int calc(LL x) {
	int res = 0;
	for(; x; x /= 10)
		++res;
	return res;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	cin >> n;
	LL p = n, q = 1;
	for(int i = 2; i <= n; ++i) {
		LL fm = q * i, fz = p * i + n * q, k = gcd(fz, fm);
		fz /= k; fm /= k; q = fm; p = fz;
	}
	if(q == 1)
		cout << p;
	else {
		LL d = p / q, cd = calc(d);
		for(int i = cd; i; --i)
			cout.put(' ');
		cout << p % q << '\n';
		if(d)
			cout << d;
		for(int i = calc(q); i; --i)
			cout.put('-');
		cout.put('\n');
		for(int i = cd; i; --i)
			cout.put(' ');
		cout << q;
	}
	cout << endl;
	return 0;
}
