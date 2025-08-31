#include <iostream>
#include <utility>
#include <algorithm>
#include <functional>
using namespace std;

pair<int, int> v[300003];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n, w;
	cin >> n >> w;
	for(int i = 1; i <= n; ++i)
		cin >> v[i].first >> v[i].second;
	sort(v + 1, v + n + 1, greater<pair<int, int>>());
	long long ans = 0;
	for(int i = 1; i <= n; ++i) {
		ans += 1LL * v[i].first * min(w, v[i].second);
		w -= min(w, v[i].second);
	}
	cout << ans;
	return 0;
}