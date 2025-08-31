#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using LL = long long;

const int N = 200003;
int a[N];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int T;
	cin >> T;
	for(int n, m; T--; ) {
		cin >> n >> m;
		LL p = 0, q = 0, ans = -0x3f3f3f3f3f3f3f3f;
		for(int i = 1, x, y; i <= n; ++i) {
			cin >> x >> y;
			if(p + x > 0 && p + 1LL * x * y < 0) {
				LL z = p / (-x);
				ans = max(ans, q + (p + p + x + x * z) * z / 2);
			}
			ans = max({ans, p + q + x, q += (p + p + x + 1LL * x * y) * y / 2});
			p += x * y;
		}
		cout << ans << '\n';
	}
	return 0;
}