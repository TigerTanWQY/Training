#include <iostream>
#include <cmath>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	cin >> n;
	int tot1 = 0, tot2 = 0;
	for(int i = 0, x; i < n; ++i) {
		cin >> x;
		tot1 += x;
	}
	for(int i = 0, x; i < n; ++i) {
		cin >> x;
		tot2 += x;
	}
	cout << (int)ceil(1.0 * (tot1 + tot2) / 2);
	cout.flush();
	return 0;
}