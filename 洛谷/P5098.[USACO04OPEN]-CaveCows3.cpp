#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	constexpr const int INF = 1e9;
	int n, a = -INF, b = INF, c = -INF, d = INF;
	cin >> n;
	for(int i = 1, x, y; i <= n; ++i) {
		cin >> x >> y;
		a = max(a, x + y);
		b = min(b, x + y);
		c = max(c, x - y);
		d = min(d, x - y);
	}
	cout << max(a - b, c - d) << endl;
	return 0;
}
