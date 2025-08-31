#include <iostream>
#include <iomanip>
#include <cmath>
#include <algorithm>
using namespace std;

pair<int, int> a[103];

double dist(const int &x1, const int &y1, const int &x2, const int &y2)
{ return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2)); }

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin >> n;
	for(int i = 1; i <= n; ++i)
		cin >> a[i].first >> a[i].second;
	double ans = 0;
	for(int i = 1; i <= n; ++i)
		for(int j = 1; j <= n; ++j)
			ans = max(ans, dist(a[i].first, a[i].second, a[j].first, a[j].second));
	cout << fixed << setprecision(6) << ans;
	return 0;
}
