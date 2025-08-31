#include <iostream>
using namespace std;

int exgcd(const int& a, const int& b, int& x, int& y) {
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
	for(int a, b, m; _T--; ) {
		cin >> a >> b >> m;
		int x, y, d = exgcd(a, m, x, y);
		if(b % d)
			cout << "impossible";
		else
			cout << b / d * (0LL + x + m) % m;
		cout << '\n';
	}
	cout.flush();
	return 0;
}