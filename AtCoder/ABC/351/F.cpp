#include <iostream>
#include <algorithm>
using namespace std;

int a[400003];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	long long ans = 0;
	for(int i = 1; i <= n; ++i) {
		cin >> a[i];
		ans += 1LL * a[i] * (i - 1);
	}
	sort(a + 1, a + n + 1);
	for(int i = n; i; --i)
		ans -= 1LL * a[i] * (n - i);
	cout << ans;
	return 0;
}