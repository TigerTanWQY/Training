#include <bits/stdc++.h>
using namespace std;
using LL = long long;

constexpr const int N = 1e5 + 3;
int x[N], y[N], fx[N], fy[N], n;
LL sx[N], sy[N];

LL calc(int i) {
	int rx = lower_bound(fx + 1, fx + n + 1, x[i]) - fx,
		ry = lower_bound(fy + 1, fy + n + 1, y[i]) - fy;
	return 1LL * rx * x[i] - 2 * sx[rx] + sx[n] - 1LL * (n - rx) * x[i] +
		1LL * ry * y[i] - 2 * sy[ry] + sy[n] - 1LL * (n - ry) * y[i];
}

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	cin >> n;
	for(int i = 1, xx, yy; i <= n; ++i) {
		cin >> xx >> yy;
		x[i] = fx[i] = xx + yy;
		y[i] = fy[i] = xx - yy;
	}
	sort(fx + 1, fx + n + 1);
	for(int i = 1; i <= n; ++i)
		sx[i] = sx[i - 1] + fx[i];
	sort(fy + 1, fy + n + 1);
	for(int i = 1; i <= n; ++i)
		sy[i] = sy[i - 1] + fy[i];
	LL ans = 1e18;
	for(int i = 1; i <= n; ++i)
		ans = min(ans, calc(i));
	cout << ans / 2 << endl;
	return 0;
}
