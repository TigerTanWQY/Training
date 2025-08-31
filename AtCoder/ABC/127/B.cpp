#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int r, d, x;
	cin >> r >> d >> x;
	for(int _ = 10; _--; cout.put('\n')) {
		x = x * r - d;
		cout << x;
	}
	cout.flush();
	return 0;
}