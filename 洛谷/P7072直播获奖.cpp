#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n, w;
	cin >> n >> w;
	vector<int> a;
	for(int p = 1, x; p <= n; ++p) {
		cin >> x;
		a.insert(lower_bound(a.cbegin(), a.cend(), x, greater<int>()), x);
		cout << a[max(1, p * w / 100) - 1] << ' ';
	}
	return 0;
}