#include <iostream>
using namespace std;
using LL = long long;

LL exgcd(const LL a, const LL b, LL &x, LL &y) {
	if(b == 0) {
		x = 1;
		y = 0;
		return a;
	}
	LL g = exgcd(b, a % b, y, x);
	y -= a / b * x;
	return g;
}

void mrge(LL& a, LL& b, const LL c, LL d) {
	if(a == -1 && b == -1)
		return;
	LL x, y, g = exgcd(b, d, x, y);
	if((c - a) % g != 0) {
		a = b = -1;
		return;
	}
	d /= g;
	LL t0 = ((c - a) / g) % d * x % d;
	if(t0 < 0)
		t0 += d;
	a += b * t0;
	b *= d;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin >> n;
	LL a = 0, b = 1;
	for(LL c, d; n--; ) {
		cin >> c >> d;
		mrge(a, b, d, c);
	}
	cout << a;
	cout << endl;
	return 0;
}