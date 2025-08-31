#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	const int n = 9;
	int tot1 = 0;
	for(int _ = 0, x; _ < n; ++_) {
		cin >> x;
		tot1 += x;
	}
	int tot2 = 0;
	for(int _ = 1, x; _ < n; ++_) {
		cin >> x;
		tot2 += x;
	}
	cout << tot1 - tot2 + 1;
	return 0;
}