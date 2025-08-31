#include <iostream>
#include <cmath>
using namespace std;
using LL = long long;

int n, x;
LL a[23];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n >> x;
	for(int i = 0; i < n; ++i)
		cin >> a[i];
	LL ans = 0x3f3f3f3f3f3f3f3f;
	for(int s = 0; s < 1 << n; ++s) {
		LL tot = 0;
		for(int i = 0; i < n; ++i)
			if(s >> i & 1)
				tot += a[i];
		ans = min(ans, abs(tot - x));
	}
	cout << ans << endl;
	return 0;
}