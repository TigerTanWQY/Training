#include <iostream>
#include <algorithm>
using namespace std;
using LL = long long;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, L, R;
	cin >> n >> L >> R;
	LL pre = 0, ans = (LL)R * n;
	for(int i = 1, x; i <= n; ++i) {
		cin >> x;
		pre = min(pre + x, (LL)i * L);
		ans = min(ans, pre + (LL)(n - i) * R);
	}
	cout << ans << endl;
	return 0;
}