#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>
using namespace std;

vector<pair<int, int>> a;
int ans[200003];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n, idx = 0;
	cin >> n;
	for(int _ = 0, x, y; _ < n; ++_) {
		cin >> x >> y;
		a.push_back({x, 1});
		a.push_back({x + y, -1});
	}
	sort(a.begin(), a.end());
	for(int i = 0; i < a.size() - 1; ++i) {
		idx += a[i].second;
		ans[idx] += ((a[i + 1].first) - (a[i].first));
	}
	for(int i = 1; i <= n; ++i)
		cout << ans[i] << ' ';
	return 0;
}