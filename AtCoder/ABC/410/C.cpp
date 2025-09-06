#include <bits/stdc++.h>
using namespace std;

int a[1000003];

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int n, _q;
	cin >> n >> _q;
	iota(a, a + n, 1);
	int eps = 0;
	for(int op, p, x, k; _q--; ) {
		cin >> op;
		if(op == 1) {
			cin >> p >> x; --p;
			a[(p + eps) % n] = x;
		} else if(op == 2) {
			cin >> p; --p;
			cout << a[(p + eps) % n] << '\n';
		} else {
			cin >> k;
			eps += k; eps %= n;
		}
	}
	cout.flush(); return 0;
}
