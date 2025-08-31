#include <iostream>
#include <unordered_map>
#include <algorithm>
using namespace std;

int c[300003];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n, k;
	cin >> n >> k;
	for(int i = 1; i <= n; ++i)
		cin >> c[i];
	unordered_map<int, int> cnt;
	for(int i = 1; i <= k; ++i)
		++cnt[c[i]];
	int ans = cnt.size();
	for(int i = k + 1; i <= n; ++i) {
		--cnt[c[i - k]];
		++cnt[c[i]];
		if(!cnt[c[i - k]])
			cnt.erase(c[i - k]);
		ans = max(ans, int(cnt.size()));
	}
	cout << ans;
	return 0;
}