#include <iostream>
using namespace std;

int c[100003];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, q;
	cin >> n >> q;
	for(int i = 1, last = 0, x; i <= n; last = x, ++i) {
		cin >> x;
		c[i] = x - last;
	}
	for(int L, R; q--; ) {
		cin >> L >> R;
		++c[L]; --c[R + 1];
	}
	for(int i = 1; i <= n; ++i) {
		c[i] += c[i - 1];
		cout << c[i] << ' ';
	}
	cout << endl;
	return 0;
}