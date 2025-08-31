#include <iostream>
#include <unordered_map>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	unordered_map<int, int> mp;
	for(int i = 1, x, c; i <= n; ++i) {
		cin >> x >> c;
		if(mp.count(c))
			mp[c] = min(mp[c], x);
		else
			mp[c] = x;
	}
	int ans = 0;
	for(const auto& p: mp)
		ans = max(ans, p.second);
	cout << ans;
	return 0;
}