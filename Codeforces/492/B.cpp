#include <bits/stdc++.h>
using namespace std;

int a[1003];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, m;
	cin >> n >> m;
	for(int i = 1; i <= n; ++i)
		cin >> a[i];
	sort(a + 1, a + n + 1);
	double ans = a[1];
	for(int i = 2; i <= n; ++i)
		ans = max(ans, (a[i] - a[i - 1]) / 2.0);
	ans = max(ans, (double) (m - a[n]));
	cout << fixed << setprecision(12) << ans << endl;
	return 0;
}
