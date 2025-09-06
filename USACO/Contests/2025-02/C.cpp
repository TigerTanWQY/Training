#include <iostream>
#include <algorithm>
using namespace std;
using LL = long long;

LL opt(LL a, LL b, LL c, LL d) {
	LL res = 0;
	while(true) {
		if(a == c && b == d)
			return res;
		else if(c < a || d < b)
			return -1;
		else if(c > d) {
			if(d == b) {
				if((c - a) % d != 0)
					return -1;
				return res + (c - a) / d;
			}
			res += c / d;
			c %= d;
		} else {
			if(c == a) {
				if((d - b) % c != 0)
					return -1;
				return res + (d - b) / c;
			}
			res += d / c;
			d %= c;
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int _T;
	cin >> _T;
	for(LL a, b, c, d; _T--; cout.put('\n')) {
		cin >> a >> b >> c >> d;
		cout << opt(a, b, c, d);
	}
	cout.flush();
	return 0;
}
