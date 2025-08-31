#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

unordered_map<int, int> cnt;
vector<int> ans;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n, maxn = 0;
	cin >> n;
	for(int i = 0, x; i < n; ++i) {
		cin >> x;
		++cnt[x];
	}
	for(const auto& x: cnt)
		if(x.second > maxn) {
			maxn = x.second;
			ans.clear();
			ans.push_back(x.first);
		} else if(x.second == maxn)
			ans.push_back(x.first);
	sort(ans.begin(), ans.end());
	for(const auto& x: ans)
		cout << x << ' ';
	return 0;
}