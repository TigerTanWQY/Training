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
	for(int a, b; _T--; ) {
		cin >> a >> b;
		LL x, y;
		exgcd(a, b, x, y);
		cout << x << ' ' << y << '\n';
	}
	cout.flush();
	return 0;
}