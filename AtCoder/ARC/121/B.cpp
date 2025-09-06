#include <bits/stdc++.h>
using namespace std;
#define int long long
#define VI vector<int>
#define sz(a) a.size()
#define all(a) a.begin(), a.end()
#define up(i, s, t) for (int i = s; i <= t; i++)
#define dw(i, s, t) for (int i = s; i >= t; i--)

signed main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int n; VI col[3];
	cin >> n;
	string ss = "RGB";
	up(i, 1, 2 * n) {
		int x; char c;
		cin >> x >> c;
		col[ss.find(c)].push_back(x);
	}
	if (sz(col[0]) % 2 == 0 && sz(col[1]) % 2 == 0 && sz(col[2]) % 2 == 0)
		return cout << 0, 0;
	if (sz(col[0]) % 2 == 0) swap(col[0], col[2]);
	else if (sz(col[1]) % 2 == 0) swap(col[1], col[2]);
	up(i, 0, 2) sort(all(col[i]));
	auto cal = [&](int c1, int c2) {
		int res = 1e18;
		for (int t : col[c1]) {
			auto tt = lower_bound(all(col[c2]), t);
			if (tt != cend(col[c2])) res = min(res, *tt - t);
			if (tt != cbegin(col[c2])) res = min(res, t - *prev(tt));
		}
		return res;
	};
	cout << min(cal(0, 1), cal(0, 2) + cal(1, 2));
	return 0;
}
