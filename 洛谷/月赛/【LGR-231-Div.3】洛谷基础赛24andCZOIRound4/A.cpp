#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int n, k1, k2;
	cin >> n >> k1 >> k2;
	int ans = -1;
	for(int a, x, y; n--; ) {
		cin >> a >> x >> y;
		if(x && y)
			continue;
		a -= k1 * x + k2 * y;
		ans = max({ans, a});
	}
	cout << ans << endl;
	return 0;
}
