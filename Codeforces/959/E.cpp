#include <iostream>
using namespace std;
using LL = long long;

LL f(LL x) {
	if(x == 1)
		return 0;
	return x / 2 + 2 * f(x / 2 + (x & 1));
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	LL n;
	cin >> n;
	cout << f(n) << endl;
	return 0;
}