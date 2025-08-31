#include <bits/stdc++.h>
using namespace std;
using LL = long long;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int a[5], n, S;
	cin >> n >> S;
	for(int i = 0; i < 5; ++i)
		cin >> a[i];
	LL ans = 0x3f3f3f3f3f3f3f3f;
	for(int i = 0; i <= n; ++i) {
		LL cnt = 0;
		if((n - i) * (LL)a[4] - S - (LL)i * a[1] > 0)
			cnt = ((n - i) * (LL)a[4] - S - (LL)i * a[1]) / (a[3] + a[4]) + 1;
		ans = min(ans, (LL)i * a[0] + cnt * a[2]);
	}
	cout << ans << endl;
	return 0;
}
