#include <bits/stdc++.h>
using namespace std;

double f[53][53];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, a, q;
	cin >> n >> a >> q;
	if(n > 50) {
		cout << "1.000" << endl;
		return 0;
	}
	double p = a / 100.0;
	f[0][0] = 1;
	for(int i = 1; i <= n; ++i) {
		char c;
		cin >> c;
		for(int j = 0; j <= i; ++j)
			if(c == '0')
				f[i][j] = f[i - 1][j] * p + f[i - 1][j - 1] * (1 - p);
			else
				f[i][j] = f[i - 1][j - 1] * p + f[i - 1][j] * (1 - p);
	}
	double ans = 0;
	for(int i = n; i >= q; --i)
		ans += f[n][i];
	cout << fixed << setprecision(3) << ans << endl;
	return 0;
}
