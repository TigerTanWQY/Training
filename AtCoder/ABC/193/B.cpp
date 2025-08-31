#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	int ans = 0x3f3f3f3f;
	for(int i = 1, t, p, x; i <= n; ++i) {
		cin >> t >> p >> x;
		if(x > t)
			ans = min(ans, p);
	}
	if(ans == 0x3f3f3f3f)
		cout << "-1";
	else
		cout << ans;
	return 0;
}