#include <iostream>
using namespace std;
using LL = long long;

constexpr const int N = 1'000'003;
int n;
LL c[N];

int lowbit(const int x)
{ return x & -x; }

LL query(int x) {
	LL res = 0;
	for(; x; x -= lowbit(x))
		res += c[x];
	return res;
}

void modify(int x, const LL w) {
	for(; x <= n; x += lowbit(x))
		c[x] += w;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int m;
	cin >> n >> m;
	for(int i = 1, x; i <= n; ++i) {
		cin >> x;
		modify(i, x);
	}
	for(int k, a, b; m--; ) {
		cin >> k >> a >> b;
		if(k == 1)
			modify(a, b);
		else
			cout << query(b) - query(a - 1) << '\n';
	}
	cout.flush();
	return 0;
}