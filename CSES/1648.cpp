#include <iostream>
using namespace std;
using LL = long long;

constexpr const int N = 2e5 + 3;
int a[N], n;
LL c[N];

int lb(int x)
{ return x & -x; }

void mdf(int x, int w) {
	for(; x <= n; x += lb(x))
		c[x] += w;
}

LL qry(int x) {
	LL res = 0;
	for(; x > 0; x -= lb(x))
		res += c[x];
	return res;
}

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int _q;
	cin >> n >> _q;
	for(int i = 1; i <= n; ++i) {
		cin >> a[i];
		mdf(i, a[i]);
	}
	for(int op, x, y; _q--; ) {
		cin >> op >> x >> y;
		if(op == 1) {
			mdf(x, y - a[x]);
			a[x] = y;
		} else
			cout << qry(y) - qry(x - 1) << '\n';
	}
	cout.flush();
	return 0;
}
