#include <iostream>
#include <algorithm>
using namespace std;
using LL = long long;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	LL k, x, ans = 1;
	cin >> k;
	for(LL i = 2; i * i <= k; ++i) {
		LL cnt = 0, n = 0;
		for(; k % i == 0; k /= i)
			++cnt;
		while(cnt > 0) {
			n += i;
			x = n;
			while(x % i == 0) {
				x /= i;
				--cnt;
			}
		}
		ans = max(ans, n);
	}
	ans = max(ans, k);
	cout << ans << endl;
	return 0;
}