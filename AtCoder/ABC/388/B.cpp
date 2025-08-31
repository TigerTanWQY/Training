#include <bits/stdc++.h>
using namespace std;

pair<int, int> a[103];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, d;
	cin >> n >> d;
	for(int i = 1; i <= n; ++i)
		cin >> a[i].first >> a[i].second;
	for(int k = 1; k <= d; ++k) {
		int res = 0;
		for(int i = 1; i <= n; ++i)
			res = max(res, a[i].first * (a[i].second + k));
		cout << res << '\n';
	}
	cout.flush();
	return 0;
}
