#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n, k;
	cin >> n >> k;
	int ans = 1;
	for(int i = 1, tot = 0, x; i <= n; ++i) {
		cin >> x;
		if(tot + x > k) {
			++ans;
			tot = x;
		} else
			tot += x;
	}
	cout << ans;
	return 0;
}