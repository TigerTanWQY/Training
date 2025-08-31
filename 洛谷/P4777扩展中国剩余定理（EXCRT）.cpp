#include <iostream>
using namespace std;
using i128 = __int128;

ostream& operator<<(ostream& fout, i128 x) {
	int s[12], k = 0;
	for(; x; x /= 10)
		s[++k] = x % 10;
	for(int i = k; i; --i)
		fout << char(s[i] + '0');
	return fout;
}

i128 exgcd(const i128 a, const i128 b, i128 &x, i128 &y) {
	if(b == 0) {
		x = 1;
		y = 0;
		return a;
	}
	i128 g = exgcd(b, a % b, y, x);
	y -= a / b * x;
	return g;
}

void mrge(i128& a, i128& b, const i128 c, i128 d) {
	if(a == -1 && b == -1)
		return;
	i128 x, y, g = exgcd(b, d, x, y);
	if((c - a) % g != 0) {
		a = b = -1;
		return;
	}
	d /= g;
	i128 t0 = ((c - a) / g) % d * x % d;
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
	i128 a = 0, b = 1;
	for(long long c, d; n--; ) {
		cin >> c >> d;
		mrge(a, b, d, c);
	}
	cout << a;
	cout << endl;
	return 0;
}