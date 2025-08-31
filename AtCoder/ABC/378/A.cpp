#include <iostream>
#include <unordered_map>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	unordered_map<int, int> mp;
	for(int _ = 4, x; _--; ) {
		cin >> x;
		++mp[x];
	}
	int ans = 0;
	for(const auto& [_, w]: mp)
		ans += w / 2;
	cout << ans << endl;
	return 0;
}