#include <iostream>
#include <cmath>
using namespace std;
using LL = long long;

int exgcd(const int& a, const int& b, LL& x, LL& y) {
	if(b == 0) {
		x = 1;
		y = 0;
		return a;
	}
	int d = exgcd(b, a % b, y, x);
	y -= x * (a / b);
	return d;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int _T;
	cin >> _T;
	for(int a, b, c; _T--; ) {
		cin >> a >> b >> c;
		LL x, y;
		const int d = exgcd(a, b, x, y);
		if(c % d) {
			cout << "-1\n";
			continue;
		}
		x *= c / d;
		y *= c / d;
		const LL p = b / d, q = a / d;
		if(x < 0) {
			const LL k = ceil((1.0 - x) / p);
			x += p * k;
			y -= q * k;
		} else
			if(x >= 0) {
				const LL k = (x - 1) / p;
				x -= p * k;
				y += q * k;
			}
		if(y > 0)
			cout << (y - 1) / q + 1 << ' ' << x << ' ' << (y - 1) % q + 1 << ' ' << x + (y - 1) / q * p << ' ' << y;
		else
			cout << x << ' ' << y + q * (LL)ceil((1.0 - y) / q);
		cout << '\n';
	}
	cout.flush();
	return 0;
}