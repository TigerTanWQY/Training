#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
using LL = long long;

LL a[10000003];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, q;
	cin >> n >> q;
	for(int op, l, r; q--; ) {
		cin >> op >> l >> r;
		switch(op) {
			case 1: {
				LL x;
				cin >> x;
				for(int i = l; i <= r; ++i)
					a[i] += x;
				break;
			}
			case 2: {
				LL x;
				cin >> x;
				for(int i = l; i <= r; ++i)
					a[i] *= x;
				break;
			}
			case 3: {
				LL x;
				cin >> x;
				for(int i = l; i <= r; ++i)
					a[i] = min(a[i], x);
				break;
			}
			case 4: {
				LL x;
				cin >> x;
				for(int i = l; i <= r; ++i)
					a[i] = max(a[i], x);
				break;
			}
			case 5: {
				LL x;
				cin >> x;
				for(int i = l; i <= r; ++i)
					a[i] = __gcd(a[i], x);
				break;
			}
			case 6: {
				LL x;
				cin >> x;
				for(int i = l; i <= r; ++i)
					a[i] |= x;
				break;
			}
			case 7: {
				LL x;
				cin >> x;
				for(int i = l; i <= r; ++i)
					a[i] &= x;
				break;
			}
			case 8: {
				LL x;
				cin >> x;
				for(int i = l; i <= r; ++i)
					a[i] ^= x;
				break;
			}
			case 9: {
				LL x, d;
				cin >> x >> d;
				for(int i = l; i <= r; ++i)
					a[i] += x + (i - l + 1) * d;
				break;
			}
			case 10: {
				LL ans = 0;
				for(int i = l; i <= r; ++i)
					ans += sin(a[i]) + cos(a[i]);
				cout << ans << '\n';
				break;
			}
			case 11: {
				LL ans = 0;
				for(int i = l; i <= r; ++i)
					for(int j = i; j <= r; ++j)
						for(int k = i; k <= j; ++k)
							ans += sin(a[k]) + cos(a[k]);
				cout << ans << '\n';
				break;
			}
		}
	}
	return 0;
}
