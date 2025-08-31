#include <iostream>
using namespace std;
using LL = long long;

constexpr const int N = 200'003;
int a[N], n;
LL c[N];

LL lowbit(const LL& x)
{ return x & (-x); }

LL query(int x) {
	LL res = 0;
	for(; x; x -= lowbit(x))
		res += c[x];
	return res;
}

void modify(int x, const LL& d) {
	for(; x <= n; x += lowbit(x))
		c[x] += d;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int q;
	cin >> n >> q;
	for(int i = 1; i <= n; ++i) {
		cin >> a[i];
		modify(i, a[i]);
	}
	for(int op, x; q--; ) {
		cin >> op >> x;
		if(op == 1) {
			int d;
			cin >> d;
			modify(x, d - a[x]);
			a[x] = d;
		} else
			cout << query(x) << '\n';
	}
	cout.flush();
	return 0;
}