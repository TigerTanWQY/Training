#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, c;
	cin >> n >> c;
	int ans = 0;
	for(int lst = -1000, x; n--; ) {
		cin >> x;
		if(x - lst >= c) {
			++ans;
			lst = x;
		}
	}
	cout << ans << endl;
	return 0;
}