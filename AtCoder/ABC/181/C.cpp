#include <iostream>
#include <utility>
#include <algorithm>
using namespace std;
using PII = pair<int, int>;

PII a[103];

bool check(const PII& x, const PII& y, const PII& z) {
	int x1 = x.first, y1 = x.second, x2 = y.first, y2 = y.second, x3 = z.first, y3 = z.second;
	x1 -= x3;
	x2 -= x3;
	y1 -= y3;
	y2 -= y3;
	if(x1 * y2 == x2 * y1)
		return true;
	else
		return false;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	for(int i = 1; i <= n; ++i)
		cin >> a[i].first >> a[i].second;
	sort(a + 1, a + n + 1);
	for(int i = 1; i < n - 1; ++i)
		for(int j = i + 1; j < n; ++j)
			for(int k = j + 1; k <= n; ++k)
				if(check(a[i], a[j], a[k])) {
					cout << "Yes";
					return 0;
				}
	cout << "No";
	return 0;
}