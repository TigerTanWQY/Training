#include <iostream>
#include <iomanip>
#include <algorithm>
using namespace std;

int a[3][10003], n;

double f(const double &x) {
	double ret = 0;
	for(int i = 1; i <= n; ++i) {
		double tot = 0;
		for(int j = 0; j <= 2; ++j)
			tot = tot * x + a[j][i];
		ret = max(ret, tot);
	}
	return ret;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int T;
	cin >> T;
	while(T--) {
		cin >> n;
		for(int i = 1; i <= n; ++i)
			cin >> a[0][i] >> a[1][i] >> a[2][i];
		double L = 0, R = 1000;
		for(int _ = 0; _ < 100; ++_) {
			double k = (R - L) / 3, LM = L + k, RM = R - k;
			if(f(LM) > f(RM))
				L = LM;
			else
				R = RM;
		}
		cout << fixed << setprecision(4) << f(L) << '\n';
	}
	return 0;
}
