#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	cin >> n;
	unordered_map<int, vector<int>> mp;
	for(int i = 1, x; i <= n; ++i) {
		cin >> x;
		mp[x].push_back(i);
	}
	long long ans = 0, tot = 0;
	vector<int> f;
	for(const auto& [_, x]: mp) {
		f.push_back(x.size());
		tot += x.size();
	}
	for(int i = 0; i + 1 < f.size(); ++i) {
		tot -= f[i];
		ans += f[i] * tot;
	}
	cout << ans << endl;
	return 0;
}
