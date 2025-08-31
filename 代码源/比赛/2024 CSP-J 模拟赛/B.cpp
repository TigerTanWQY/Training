#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
using LL = long long;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int _T;
	cin >> _T;
	for(LL x; _T--; cout.put('\n')) {
		cin >> x;
		for(LL i = sqrt(x); i; --i)
			if(x % i == 0 && __gcd(i, x / i) == 1) {
				cout << i << ' ' << x / i;
				break;
			}
	}
	cout.flush();
	return 0;
}