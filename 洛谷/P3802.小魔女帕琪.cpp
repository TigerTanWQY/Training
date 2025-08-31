#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int a[8], tot = 0;
	for(int i = 1; i <= 7; ++i) {
		cin >> a[i];
		tot += a[i];
	}
	double ans = 1;
	for(int i = 1; i <= 6; ++i)
		ans *= 1.0 * a[i] / (tot + 1 - i) * i;
	ans *= a[7] * 7;
	cout << fixed << setprecision(3) << ans << endl;
	return 0;
}
