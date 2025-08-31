#include <iostream>
#include <iomanip>
#include <cmath>
#include <algorithm>
using namespace std;

constexpr const double PI = acos(-1);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, m;
	cin >> n >> m;
	double ans = 0;
	for(int i = 1; i <= n; ++i) {
		ans += 2 * m * i;
		for(int j = 1; j < m; ++j)
			ans += min(2 * i * j * PI, (double) (4 * m * i));
		if(m > 1)
			ans += 2 * m * i;
	}
	for(int i = 1; i <= n; ++i)
		for(int j = i + 1; j <= n; ++j) {
			ans += 4 * j * m;
			for(int k = 1; k < m; ++k)
				ans += 4 * m * min(PI * i * k / m + j - i, (double) (i + j));
		}
	cout << fixed << setprecision(6) << ans << endl;
	return 0;
}