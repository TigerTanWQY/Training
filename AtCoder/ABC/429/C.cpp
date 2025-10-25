#include <bits/stdc++.h>
using namespace std;

int cnt[200003];

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int n;
	cin >> n;
	for(int i = 0, x; i < n; ++i) {
		cin >> x;
		++cnt[x];
	}
	long long ans = 0;
	for(int x = 1; x <= n; ++x)
		if(cnt[x] >= 2)
			ans += 1LL * cnt[x] * (cnt[x] - 1) / 2 * (n - cnt[x]);
	cout << ans << endl;
	return 0;
}
