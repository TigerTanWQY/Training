#include <bits/stdc++.h>
using namespace std;
using LL = long long;

LL cnt[1000003];

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	for(int i = 0, a, b; i < m; ++i) {
		cin >> a >> b;
		++cnt[(a + b) % n];
	}
	LL ans = (LL)m * (m - 1) / 2;
	for(const auto& x: cnt)
		ans -= x * (x - 1) / 2;
	cout << ans << endl;
	return 0;
}
