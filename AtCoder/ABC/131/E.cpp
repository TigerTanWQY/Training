#include <iostream>
#include <utility>
#include <vector>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n, k;
	cin >> n >> k;
	vector<pair<int, int>> ans;
	for(int i = 1; i < n; ++i)
		ans.push_back({0, i});
	int m = (n - 2) * (n - 1) / 2;
	if(k > m) {
		cout << "-1";
		return 0;
	}
	for(int i = 1; i < n - 1; ++i)
		for(int j = i + 1; j < n; ++j)
			if(k != m) {
				ans.push_back({i, j});
				--m;
			}
	cout << ans.size() << '\n';
	for(const auto& p: ans)
		cout << p.first + 1 << ' ' << p.second + 1 << '\n';
	return 0;
}