#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> cnt[3];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	for(int i = 1, x; i <= n; ++i) {
		cin >> x;
		cnt[x % 3].push_back(i);
	}
	auto ans = min({cnt[0].size(), cnt[1].size(), cnt[2].size()});
	cout << ans << '\n';
	for(int i = 0; i < ans; ++i)
		cout << cnt[0][i] << ' ' << cnt[1][i] << ' ' << cnt[2][i] << '\n';
	cout << flush;
	return 0;
}