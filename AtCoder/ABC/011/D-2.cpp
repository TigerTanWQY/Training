#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, d, ex, ey;
	cin >> n >> d >> ex >> ey;
	if(ex < 0) ex = -ex;
	if(ey < 0) ey = -ey;
	if(ex % d || ey % d) {
		cout << "0.0000000000" << endl;
		return 0;
	}
	ex /= d; ey /= d;
	if(((ex + ey) & 1) ^ (n & 1)) {
		cout << "0.0000000000" << endl;
		return 0;
	}
	double ans = 1;
	long long R = (ex + ey + n) >> 1, L = (ex - ey + n) >> 1;
	for(double k = 1; k <= n; ++k) {
		ans /= 4.0;
		if(k <= R) ans *= (k + n - R) / k;
		if(k <= L) ans *= (k + n - L) / k;
	}
	cout << fixed << setprecision(10) << ans << endl;
	return 0;
}
