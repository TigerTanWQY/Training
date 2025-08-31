#include <iostream>
#include <iomanip>
#include <algorithm>
using namespace std;

int main() {
	int n;
	cin >> n;
	double ans = 3.5;
	for(int i = 1; i < n; ++i) {
		double tot = 0;
		for(int d = 1; d <= 6; ++d)
			tot += max(ans, 1.0 * d) / 6;
		ans = tot;
	}
	cout << fixed << setprecision(6) << ans;
	return 0;
}
