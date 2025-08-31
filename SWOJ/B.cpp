#include <iostream>
#include <iomanip>
#include <queue>
#include <algorithm>
using namespace std;

const int N = 500013;
pair<int, int> a[N];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, x, m = 0;
	cin >> n >> x;
	for(int i = 1; i <= n; ++i) {
		cin >> a[i].first >> a[i].second;
		if(a[i].second)
			++m;
	}
	sort(a + 1, a + n + 1);
	queue<int> d[2];
	int ans0 = 0, ans1 = 0;
	for(int i = 1; i <= n; ++i) {
		d[a[i].second].push(a[i].first);
		while(!d[0].empty() && d[0].front() + x <= a[i].first)
			d[0].pop();
		while(!d[1].empty() && d[1].front() + x <= a[i].first)
			d[1].pop();
		ans0 = max(ans0, (int) (d[0].size() + d[1].size()));
		ans1 = max(ans1, (int)d[1].size());
	}
	if(m)
		cout << fixed << setprecision(7) << ans0 * 100.0 / n + ans1 * 1.0 / m << '%';
	else
		cout << fixed << setprecision(7) << ans0 * 100.0 / n << '%';
	return 0;
}
