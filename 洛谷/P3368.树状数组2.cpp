#include <iostream>
using namespace std;
using LL = long long;

constexpr const int N = 500'003;
int a[N], d[N], n;
LL c[N];

LL lowbit(const LL& x)
{ return x & (-x); }

LL query(int x) {
	LL res = 0;
	for(; x; x -= lowbit(x))
		res += c[x];
	return res;
}

void modify(int x, const LL& k) {
	for(; x <= n; x += lowbit(x))
		c[x] += k;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int q;
	cin >> n >> q;
	for(int i = 1; i <= n; ++i) {
		cin >> a[i];
		d[i] = a[i] - a[i - 1];
		modify(i, d[i] - d[i - 1]);
	}
	for(int op, x; q--; ) {
		cin >> op >> x;
		if(op == 1) {
			int y, k;
			cin >> y >> k;
			modify(x, k);
			modify(y + 1, -k);
		} else
			cout << query(x) << '\n';
	}
	cout.flush();
	return 0;
}