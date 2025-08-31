#include <iostream>
#include <algorithm>
using namespace std;

int f[200003];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	int ans = -2e9;
	for(int i = 1, x; i <= n; ++i) {
		cin >> x;
		ans = max(ans, f[i] = max(x, f[i - 1] + x));
	}
	cout << ans;
	return 0;
}