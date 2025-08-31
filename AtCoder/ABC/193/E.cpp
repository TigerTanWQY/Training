#include <iostream>
#include <algorithm>
#include <atcoder/math>
using namespace std;
using atcoder::crt;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int T;
	cin >> T;
	for(int x, y, p, q; T--; ) {
		cin >> x >> y >> p >> q;
		long long ans = 0x3f3f3f3f3f3f3f3f;
		for(int t1 = x; t1 < x + y; ++t1)
			for(int t2 = p; t2 < p + q; ++t2) {
				auto k = crt({t1, t2}, {(x + y) * 2LL, p + q});
				if(k.second == 0)
					continue;
				ans = min(ans, k.first);
			}
		if(ans == 0x3f3f3f3f3f3f3f3f)
			cout << "infinity";
		else
			cout << ans;
		cout << '\n';
	}
	return 0;
}