#include <iostream>
#include <vector>
#include <map>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	cin >> n;
	map<int, int> mp;
	for(int i = 1, x; i <= n; ++i) {
		cin >> x;
		++mp[x];
	}
	vector<pair<int, int>> a;
	for(auto&& p: mp)
		a.emplace_back(move(p));
	int ans = 0;
	for(int i = 1, cnt = a.front().second; i < a.size(); ++i)
		if(a[i].second >= cnt) {
			ans += cnt;
			cnt = a[i].second;
		} else {
			ans += a[i].second;
			cnt -= a[i].second;
		}
	cout << n - ans << endl;
	return 0;
}