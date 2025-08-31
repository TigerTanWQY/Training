#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	cin >> n;
	int ans = 0;
	for(int x; n--; ) {
		cin >> x;
		ans += max(0, x - 10);
	}
	cout << ans << endl;
	return 0;
}
