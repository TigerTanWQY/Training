#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n, k, p, q, cnt = 0;
	cin >> n >> k >> p >> q;
	for(; 1.0 * k / n > 1.0 * p / q; ++cnt, ++n);
	cout << cnt;
	return 0;
}