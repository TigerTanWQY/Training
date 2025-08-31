#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int _T;
	cin >> _T;
	for(int x; _T--; ) {
		cin >> x;
		int ans = 0;
		for(; x; x /= 10)
			ans += x % 10;
		cout << ans << '\n';
	}
	cout.flush();
	return 0;
}