#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, W, _q;
	cin >> n >> W;
	for(int i = 1, x, y; i <= n; ++i) {
		cin >> x >> y;
	}
	cin >> _q;
	for(int t, a; _q--; cout.put('\n')) {
		cin >> t >> a;
	}
	cout.flush();
	return 0;
}
