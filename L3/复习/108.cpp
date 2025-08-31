#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int _T;
	cin >> _T;
	for(int x, y; _T--; cout.put('\n')) {
		cin >> x >> y;
		cout << __gcd(x, y);
	}
	cout.flush();
	return 0;
}