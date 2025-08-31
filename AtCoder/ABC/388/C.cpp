#include <bits/stdc++.h>
using namespace std;

int a[500003];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	cin >> n;
	for(int i = 1; i <= n; ++i)
		cin >> a[i]; // Sorted
	long long ans = 0;
	for(int i = 1; i <= n; ++i) {
		auto it = lower_bound(a + i, a + n + 1, a[i] << 1);
		if(it != a + n + 1)
			ans += n - (it - a) + 1;
	}
	cout << ans << endl;
	return 0;
}
