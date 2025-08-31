#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	int cnt = 0, ans = 0;
	for(int i = 1, x, last = 0; i <= n; ++i) {
		cin >> x;
		cnt = min(cnt + x - last, 50);
		while(cnt >= 8) {
			cnt -= 8;
			++ans;
		}
		last = x;
	}
	cout << ans;
	return 0;
}