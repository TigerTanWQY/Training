#include <iostream>
using namespace std;
using LL = long long;

constexpr const int N = 100003;
int n;
LL c[N];

int lowbit(const int x)
{ return x & -x; }

void modify(int x, const int w) {
	for(; x <= n; x += lowbit(x))
		c[x] += w;
}

LL query(int x) {
	LL res = 0;
	for(; x; x -= lowbit(x))
		res += c[x];
	return res;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int q;
	cin >> n >> q;
	for(char op; q--; ) {
		int x, y;
		cin >> op >> x >> y;
		if(op == 'x')
			modify(x, y);
		else
			cout << query(y) - query(x - 1) << '\n';
	}
	cout.flush();
	return 0;
}