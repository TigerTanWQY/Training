#include <iostream>
#include <utility>
#include <algorithm>
using namespace std;

pair<int, int> a[34];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int _T;
	cin >> _T;
	for(int n, m; _T--; cout.put('\n')) {
		cin >> n >> m;
		int ans = 0;
		for(int i = n; i; --i)
			cin >> a[i].first >> a[i].second;
		a[n + 1].first = 0x7fffffff;
		a[n + 1].second = 1;
		for(int i = 1; i <= n + 1; ++i) {
			const int x = min(a[i].first, m / a[i].second);
			ans += x;
			m -= a[i].second * x;
		}
		cout << ans;
	}
	cout.flush();
	return 0;
}