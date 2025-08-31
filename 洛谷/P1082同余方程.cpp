#include <iostream>
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
	int a, b;
	cin >> a >> b;
	LL x, y;
	exgcd(a, b, x, y);
	x = (x % b + b) % b;
	cout << x;
	cout << endl;
	return 0;
}