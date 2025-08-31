#include <iostream>
#include <vector>
#include <array>
#include <algorithm>
using namespace std;

constexpr const int N = 500'003;
vector<array<int, 4>> event;
vector<int> vx;
int c[N], ans[N], m;

int lb(const int x)
{ return x & -x; }

int query(int x) {
	int res = 0;
	for(; x; x -= lb(x))
		res += c[x];
	return res;
}

void modify(int x, int w) {
	for(; x <= m; x += lb(x))
		c[x] += w;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, q;
	cin >> n >> q;
	for(int i = 1, x, y; i <= n; ++i) {
		cin >> x >> y;
		vx.push_back(x);
		event.push_back({y, 0, x});
	}
	sort(vx.begin(), vx.end());
	vx.erase(unique(vx.begin(), vx.end()), vx.cend());
	m = vx.size();
	for(int i = 1, x1, y1, x2, y2; i <= q; ++i) {
		cin >> x1 >> y1 >> x2 >> y2;
		event.push_back({y2, 2, x2, i});
		event.push_back({y1 - 1, 2, x1 - 1, i});
		event.push_back({y2, 1, x1 - 1, i});
		event.push_back({y1 - 1, 1, x2, i});
	}
	sort(event.begin(), event.end());
	for(const auto& evt: event)
		if(evt[1] == 0) {
			int y = lower_bound(vx.cbegin(), vx.cend(), evt[2]) - vx.cbegin() + 1;
			modify(y, 1);
		} else {
			int y = upper_bound(vx.cbegin(), vx.cend(), evt[2]) - vx.cbegin(), tmp = query(y);
			if(evt[1] == 1)
				ans[evt[3]] -= tmp;
			else
				ans[evt[3]] += tmp;
		}
	for(int i = 1; i <= q; ++i)
		cout << ans[i] << '\n';
	cout.flush();
	return 0;
}