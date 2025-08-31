#include <iostream>
#include <utility>
#include <algorithm>
using namespace std;

pair<int, char> a[200003];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, x, ans = 0;
	string s;
	cin >> n >> s;
	for(int i = 0; i < n; ++i) {
		cin >> x;
		a[i] = {x, s[i]};
		if(s[i] == '1')
			++ans;
	}
	sort(a, a + n);
	x = ans;
	for(int i = 0; i < n; i++) {
		if(a[i].second == '1')
			--x;
		else
			++x;
		if(i < n - 1) {
			if(a[i].first != a[i + 1].first)
				ans = max(ans, x);
		} else
			ans = max(ans, x);
	}
	cout << ans << endl;
	return 0;
}