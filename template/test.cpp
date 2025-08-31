#include <iostream>
using namespace std;
#include "BIT.hpp"
using namespace tiger;
using ULL = unsigned long long;

constexpr const int N = 200'003;
BIT<ULL> c;
int a[N];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, q;
	cin >> n >> q;
	for(int i = 1; i <= n; ++i)
		cin >> a[i];
	for(int op, x; q--; ) {
		cin >> op >> x;
		if(op == 1) {
			int d;
			cin >> d;
			c.modify(x, d - a[x]);
		} else
			cout << c.query(x) << '\n';
	}
	return 0;
}