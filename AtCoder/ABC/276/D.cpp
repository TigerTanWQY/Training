#include <iostream>
#include <algorithm>
using namespace std;

int a[1003];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n, g = 0, ans = 0;
	cin >> n;
	for(int i = 0; i < n; ++i) {
		cin >> a[i];
		g = __gcd(g, a[i]);
	}
	for(int i = 0; i < n; ++i) {
		a[i] /= g;
		for(; !(a[i] & 1); a[i] >>= 1)
			++ans;
		for(; !(a[i] % 3); a[i] /= 3)
			++ans;
		if(a[i] != 1) {
			cout << "-1";
			return 0;
		}
	}
	cout << ans;
	return 0;
}