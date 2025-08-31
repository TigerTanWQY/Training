#include <iostream>
using namespace std;

int c[100003];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m;
	cin >> n >> m;
	for(int i = 1, last = 0, x; i <= n; ++i) {
		cin >> x;
		c[i] = x - last;
		last = x;
	}
	for(int L, R, w; m--; ) {
		cin >> L >> R >> w;
		c[L] += w;
		c[R + 1] -= w;
	}
	for(int i = 1; i <= n; ++i) {
		c[i] += c[i - 1];
		cout << c[i] << ' ';
	}
	return 0;
}