#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n, s, t, w;
	cin >> n >> s >> t >> w;
	int ans = 0;
	for(int _ = 1, x; _ < n; ++_) {
		if(s <= w && w <= t)
			++ans;
		cin >> x;
		w += x;
	}
	if(s <= w && w <= t)
		++ans;
	cout << ans << '\n';
	return 0;
}