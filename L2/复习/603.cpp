#include <iostream>
#include <algorithm>
using namespace std;

long long s[100003];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	cin >> n;
	long long ans = -0x3f3f3f3f3f3f3f3f, tot = 0, minn = 0;
	for(int i = 1, x; i <= n; ++i) {
		cin >> x;
		tot += x;
		ans = max(ans, tot - minn);
		minn = min(minn, tot);
	}
	cout << ans << endl;
	return 0;
}