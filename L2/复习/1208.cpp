#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, x;
	cin >> n >> x;
	int ans = 0;
	for(int i = 1; i <= n; ++i) {
		string s = to_string(i);
		ans += count(s.cbegin(), s.cend(), '0' + x);
	}
	cout << ans << endl;
	return 0;
}