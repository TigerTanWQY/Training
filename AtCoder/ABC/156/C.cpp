#include <iostream>
#include <algorithm>
using namespace std;
using LL = long long;

int a[103];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	cin >> n;
	for(int i = 1; i <= n; ++i)
		cin >> a[i];
	LL ans = 0x3f3f3f3f3f3f3f3f;
	for(int i = 1; i <= 100; ++i) {
		LL tot = 0;
		for(int j = 1; j <= n; ++j)
			tot += (LL)(i - a[j]) * (i - a[j]);
		ans = min(ans, tot);
	}
	cout << ans;
	cout.flush();
	return 0;
}