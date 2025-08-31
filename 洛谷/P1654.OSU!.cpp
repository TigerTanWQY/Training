#include <iostream>
#include <iomanip>
using namespace std;

constexpr const int N = 1e5 + 3;
double a[N], b[N], f[N], p[N];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	cin >> n;
	for(int i = 1; i <= n; ++i) {
		cin >> p[i];
		a[i] = (a[i - 1] + 1) * p[i];
		b[i] = (b[i - 1] + 2 * a[i - 1] + 1) * p[i];
		f[i] = f[i - 1] + (3 * b[i - 1] + 3 * a[i - 1] + 1) * p[i];
	}
	cout << fixed << setprecision(1) << f[n] << endl;
	return 0;
}
