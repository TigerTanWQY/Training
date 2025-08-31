#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int x, y;
	cin >> x >> y;
	cout << 12 * (x - 2016) + (y - 7);
	cout.flush();
	return 0;
}