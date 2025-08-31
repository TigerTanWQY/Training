#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	unsigned n;
	cin >> n;
	cout << (n >> 16) + (n << 16) << endl;
	return 0;
}