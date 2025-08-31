#include <iostream>
#include <algorithm>
using namespace std;
using LL = long long;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	LL a, b;
	int c, d;
	cin >> a >> b >> c >> d;
	LL n = b - a + 1;
	LL Lc = a / c * c;
	if(Lc < a)
		Lc += c;
	LL Rc = b / c * c, vc = (Rc - Lc) / c + 1;
	LL Ld = a / d * d;
	if(Ld < a)
		Ld += d;
	LL Rd = b / d * d, vd = (Rd - Ld) / d + 1;
	LL cd = 1LL * c * d / __gcd(c, d);
	LL Lcd = a / cd * cd;
	if(Lcd < a)
		Lcd += cd;
	LL Rcd = b / cd * cd, vcd = (Rcd - Lcd) / cd + 1;
	cout << n - vc - vd + vcd;
	return 0;
}