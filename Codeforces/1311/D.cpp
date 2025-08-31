#include <iostream>
#include <cmath>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int T;
	cin >> T;
	for(int a, b, c; T--; ) {
		cin >> a >> b >> c;
		int x, y, z, ans = 0x3f3f3f3f;
		for(int i = 1; i <= 15000; ++i) {
			int tot = abs(b - i), minn = 0x3f3f3f3f, L, R;
			for(int j = 1; j <= sqrt(i); ++j)
				if(!(i % j)) {
					if(abs(a - j) < minn) {
						minn = abs(a - j);
						L = j;
					} if(abs(a - i / j) < minn) {
						minn = abs(a - i / j);
						L = i / j;
					}
				}
			tot += minn;
			minn = 0x3f3f3f3f;
			for(int j = i; j <= 32000; j += i)
				if(abs(c - j) < minn) {
					R = j;
					minn = abs(c - j);
				}
			tot += minn;
			if(tot < ans) {
				ans = tot;
				x = L;
				y = i;
				z = R;
			}
		}
		cout << ans << '\n' << x << ' ' << y << ' ' << z << '\n';
	}
	return 0;
}