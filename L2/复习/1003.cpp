#include <iostream>
#include <algorithm>
using namespace std;
using PII = pair<int, int>;
#define _x first
#define _y second

constexpr const int N = 1e5 + 3;
PII a[N];
int f[N];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	PII p1, p2;
	int n;
	cin >> p1._x >> p1._y >> p2._x >> p2._y >> n;
	for(int i = 1; i <= n; ++i) {
		PII p;
		cin >> p._x >> p._y;
		a[i] = {(p._x - p1._x) * (p._x - p1._x) + (p._y - p1._y) * (p._y - p1._y), (p._x - p2._x) * (p._x - p2._x) + (p._y - p2._y) * (p._y - p2._y)};
	}
	sort(a + 1, a + n + 1);
	for(int i = n; i; --i)
		f[i] = max(f[i + 1], a[i]._y);
	int ans = 0x3f3f3f3f;
	for(int i = 0; i <= n; ++i)
		ans = min(ans, a[i]._x + f[i + 1]);
	cout << ans << endl;
	return 0;
}