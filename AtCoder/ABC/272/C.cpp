#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n, maxe1 = 0, maxe2 = 0, maxo1 = 0, maxo2 = 0;
	cin >> n;
	for(int i = 1, x; i <= n; ++i) {
		cin >> x;
		if(x & 1) {
			if(x > maxo1) {
				maxo2 = maxo1;
				maxo1 = x;
			} else if(x > maxo2)
				maxo2 = x;
		} else
			if(x > maxe1) {
				maxe2 = maxe1;
				maxe1 = x;
			} else if(x > maxe2)
				maxe2 = x;
	}
	int ans = max(maxe1 + maxe2, maxo1 + maxo2);
	if(ans & 1)
		ans = -1;
	cout << ans;
	return 0;
}