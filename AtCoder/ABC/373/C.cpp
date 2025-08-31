#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	cin >> n;
	int maxa = -1e9, maxb = -1e9;
	for(int i = 1, x; i <= n; ++i) {
		cin >> x;
		maxa = max(maxa, x);
	}
	for(int i = 1, x; i <= n; ++i) {
		cin >> x;
		maxb = max(maxb, x);
	}
	cout << maxa + maxb << endl;
	return 0;
}