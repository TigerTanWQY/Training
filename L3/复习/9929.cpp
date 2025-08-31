#include <iostream>
#include <utility>
#include <algorithm>
using namespace std;

constexpr const int N = 503;
pair<int, int> a[N];
int f[N], g[N];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, k;
	cin >> n >> k;
	for(int i = 1; i <= n; ++i)
		cin >> a[i].first >> a[i].second;
	sort(a + 1, a + n + 1);
	f[1] = 1; g[1] = k;
	for(int i = 2; i <= n; ++i) {
		f[i] = 1;
		g[i] = k;
		for(int j = 1; j < i; ++j)
			if((a[i].first - a[j].first == 1 && a[i].second == a[j].second) || (a[i].second - a[j].second == 1 && a[i].first == a[j].first)) {
				f[i] = max(f[i], f[j] + 1);
				g[i] = g[j];
			} else if(g[j] && ((a[i].first - a[j].first == 2 && a[i].second == a[j].second) ||
					(a[i].second - a[j].second == 2 && a[i].first == a[j].first) ||
					(a[i].first - a[j].first == 1 && a[i].second - a[j].second == 1)) &&
					f[j] + 2 + g[j] - 1 > f[i] + g[i]) {
				g[i] = g[j] - 1;
				f[i] = f[j] + 2;
			}
	}
	int ans = 0;
	for(int i = 1; i <= n; ++i)
		ans = max(ans, f[i] + g[i]);
	cout << ans << endl;
	return 0;
}