#include <bits/stdc++.h>
using namespace std;
using LL = long long;

LL f(LL x) {
	string s = to_string(x);
	reverse(s.begin(), s.end());
	return stoll(s);
}

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int x, y;
	cin >> x >> y;
	LL a1 = x, a2 = y, a3;
	for(int i = 3; i <= 10; ++i) {
		a3 = f(a1 + a2);
		a1 = a2;
		a2 = a3;
	}
	cout << a2 << endl;
	return 0;
}
