#include <iostream>
#include <unordered_map>
using namespace std;

unordered_map<int, int> cnt;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m = 0, ans = 0;
	cin >> n;
	for(int _ = 0, x; _ < n; ++_) {
		cin >> x;
		++cnt[x];
	}
	for(const auto& x: cnt) {
		ans += x.second / 2 * 2;
		if(x.second & 1)
			++m;
	}
	if(m)
		++ans;
	cout << ans;
	return 0;
}