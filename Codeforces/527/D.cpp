#include <bits/stdc++.h>
using namespace std;

pair<int, int> a[2000003];

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int n;
	cin >> n;
	for(int i = 1, x, w; i <= n; ++i) {
		cin >> x >> w;
		a[i] = {x + w, x - w};
	}
	sort(a + 1, a + n + 1);
	int ans = 1;
	for(int i = 2, R = a[1].first; i <= n; ++i) {
		auto [r, l] = a[i];
		if(l >= R) {
			R = r;
			++ans;
		}
	}
	cout << ans << endl;
	return 0;
}
