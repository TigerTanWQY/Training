#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	long long ans = 0;
	for(int L, R; n--; ) {
		cin >> L >> R;
		ans += 1LL * (L + R) * (R - L + 1) / 2;
	}
	cout << ans;
	return 0;
}