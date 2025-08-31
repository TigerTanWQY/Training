#include <iostream>
#include <utility>
#include <algorithm>
using namespace std;

pair<int, int> a[50003];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	cin >> n;
	for(int i = 1; i <= n; ++i) {
		cin >> a[i].second >> a[i].first;
		a[i].first += a[i].second;
	}
	sort(a + 1, a + n + 1);
	int ans = -0x3f3f3f3f;
	for(int i = 1, tot = 0; i <= n; ++i) {
		ans = max(ans, tot - a[i].first + a[i].second);
		tot += a[i].second;
	}
	cout << ans;
	cout.flush();
	return 0;
}