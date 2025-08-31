#include <iostream>
#include <cmath>
using namespace std;
#define double long double

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	double x, y, r;
	cin >> x >> y >> r;
	r += 1e-14;
	long long ans = 0;
	for(double i = ceil(x - r); i <= floor(x + r); ++i) {
		double t = sqrt(r * r - (x - i) * (x - i));
		ans += floor(y + t) - ceil(y - t) + 1;
	}
	cout << ans;
	return 0;
}