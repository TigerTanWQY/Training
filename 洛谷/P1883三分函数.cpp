#include <bits/stdc++.h>
using namespace std;

constexpr const int N = 1e4 + 3;
int a[N], b[N], c[N], n;

double f(double x) {
	double res = -1e18;
	for(int i = 1; i <= n; ++i)
		res = max(res, a[i]*x*x + b[i]*x + c[i]);
	return res;
}

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int _T;
	cin >> _T;
	for(; _T--; cout.put('\n')) {
		cin >> n;
		for(int i = 1; i <= n; ++i)
			cin >> a[i] >> b[i] >> c[i];
		double L = 0, R = 1000;
		for(int _ = 0; _ < 1000; ++_) {
			double k = (R - L) / 3, LM = L + k, RM = R - k;
			if(f(LM) > f(RM))
				L = LM;
			else
				R = RM;
		}
		cout << fixed << setprecision(4) << f(L);
	}
	cout.flush(); return 0;
}
