#include <iostream>
#include <algorithm>
using namespace std;
using LL = long long;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, k;
	cin >> n >> k;
	LL ans = (LL)n * k;
	for(int L = 1, R; L <= n; L = R + 1) {
		if(k / L != 0)
			R = min(k / (k / L), n);
		else
			R = n;
		ans -= (LL) (k / L) * (R - L + 1) * (L + R) / 2;
	}
	cout << ans << endl;
	return 0;
}
