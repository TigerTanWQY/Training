#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	cin >> n;
	int ans = 0x3f3f3f3f;
	for(int i = 0, x, y; i < 3; ++i) {
		cin >> x >> y;
		ans = min(ans, y * (n / x + !!(n % x)));
	}
	cout << ans << endl;
	return 0;
}