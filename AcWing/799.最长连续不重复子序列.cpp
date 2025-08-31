#include <iostream>
#include <unordered_map>
using namespace std;

int a[100003];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	int ans = 0, i = 1, j = 1;
	unordered_map<int, int> cnt;
	for(; i <= n && j <= n; ++j) {
		cin >> a[j];
		++cnt[a[j]];
		if(cnt[a[j]] > 1) {
			ans = max(ans, j - i);
			for(; a[i] != a[j]; ++i)
				if(--cnt[a[i]])
					cnt.erase(a[i]);
			++i;
		}
	}
	ans = max(ans, j - i);
	cout << ans;
	return 0;
}