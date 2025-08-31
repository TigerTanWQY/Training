#include <iostream>
#include <utility>
#include <algorithm>
using namespace std;

pair<int, int> seg[100003];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int st, ed, n;
	cin >> st >> ed >> n;
	for(int i = 1; i <= n; ++i)
		cin >> seg[i].first >> seg[i].second;
	sort(seg + 1, seg + n + 1);
	bool flag = false;
	int ans = 0;
	for(int i = 1; i <= n; ) {
		int maxR = -1e9 - 1;
		for(; i <= n && seg[i].first <= st; ++i)
			maxR = max(maxR, seg[i].second);
		if(maxR < st) {
			flag = false;
			break;
		} else if(maxR >= st) {
			st = maxR;
			++ans;
			if(maxR >= ed) {
				flag = true;
				break;
			}
		}
	}
	if(flag)
		cout << ans;
	else
		cout << "-1";
	return 0;
}