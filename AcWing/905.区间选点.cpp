#include <iostream>
#include <utility>
#include <algorithm>
using namespace std;

pair<int, int> a[100003];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	cin >> n;
	for(int i = 1; i <= n; ++i)
		cin >> a[i].first >> a[i].second;
	sort(a + 1, a + n + 1);
	int ans = 1, maxn = a[1].second;
	for(int i = 2; i <= n; ++i)
		if(a[i].first > maxn) {
			++ans;
			maxn = a[i].second;
		} else
			maxn = min(maxn, a[i].second);
	cout << ans;
	cout.flush();
	return 0;
}