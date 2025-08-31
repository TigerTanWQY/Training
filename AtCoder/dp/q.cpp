#include <iostream>
#include <algorithm>
using namespace std;
using LL = long long;

constexpr const int N = 2e5 + 3;
int n, a[N], w[N];
LL c[N];

int lowbit(const int x)
{ return x & -x; }

void modify(int x, const LL y) {
	for(; x <= n; x += lowbit(x))
		c[x] = max(c[x], y);
}

LL query(int x) {
	LL res = 0;
	for(; x; x -= lowbit(x))
		res = max(res, c[x]);
	return res;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n;
	for(int i = 1; i <= n; ++i)
		cin >> a[i];
	for(int i = 1; i <= n; ++i)
		cin >> w[i];
	LL ans = 0;
	for(int i = 1; i <= n; ++i) {
		const LL x = query(a[i] - 1) + w[i];
		modify(a[i], x);
		ans = max(ans, x);
	}
	cout << ans << endl;
	return 0;
}