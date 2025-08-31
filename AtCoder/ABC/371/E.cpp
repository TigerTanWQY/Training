#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

constexpr const int N = 2e5 + 3;
vector<int> points;
int a[N], d[N], lst[N], n;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n;
	for(int i = 1; i <= n; ++i) {
		cin >> a[i];
		points.push_back(a[i]);
	}
	sort(points.begin(), points.end());
	points.erase(unique(points.begin(), points.end()), points.cend());
	for(int i = 1; i <= n; ++i) {
		a[i] = lower_bound(points.cbegin(), points.cend(), a[i]) - points.cbegin();
		lst[i] = d[a[i]];
		d[a[i]] = i;
	}
	long long ans = 0, tot = 0;
	for(int i = 1; i <= n; ++i) {
		tot += i - lst[i];
		ans += tot;
	}
	cout << ans << endl;
	return 0;
}