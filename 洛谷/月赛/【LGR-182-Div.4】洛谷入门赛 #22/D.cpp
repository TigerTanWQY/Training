#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	int maxn = -2e9, minn = 2e9;
	for(int _ = 0, x; _ < n; ++_) {
		cin >> x;
		maxn = max(maxn, x);
		minn = min(minn, x);
	}
	cout << 0LL + maxn + minn;
	return 0;
}