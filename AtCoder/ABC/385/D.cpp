#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
using LL = long long;
#define mkp make_pair

__gnu_pbds::gp_hash_table<LL, vector<LL>> r, c;
bitset<200003> ans;
pair<int, int> a[200003];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, m;
	LL x, y;
	cin >> n >> m >> x >> y;
	for(int i = 1; i <= n; ++i)
		cin >> a[i].first >> a[i].second;
	sort(a + 1, a + n + 1);
	for(int i = 1; i <= n; ++i) {
		r[a[i].first].push_back(a[i].second);
		c[a[i].second].push_back(a[i].first);
	}
	for(auto& [_, p]: c)
		sort(begin(p), end(p));
	auto f = [&n, &m](int i, int j)
	{ return lower_bound(a + 1, a + n + 1, mkp(i, j)) - a; };
	for(int d; m--; ) {
		char ch;
		cin >> ch >> d;
		if(ch == 'U') {
			if(!r[x].empty())
				for(auto it = upper_bound(cbegin(r[x]), cend(r[x]), y);
					it <= --upper_bound(cbegin(r[x]), cend(r[x]), y + d); ++it)
					ans[f(x, *it)] = true;
			else
				r.erase(x);
			y += d;
		} else if(ch == 'D') {
			if(!r[x].empty())
				for(auto it = lower_bound(cbegin(r[x]), cend(r[x]), y - d);
					it <= --lower_bound(cbegin(r[x]), cend(r[x]), y); ++it)
					ans[f(x, *it)] = true;
			else
				r.erase(x);
			y -= d;
		} else if(ch == 'L') {
			if(!c[y].empty())
				for(auto it = lower_bound(cbegin(c[y]), cend(c[y]), x - d);
					it <= --lower_bound(cbegin(c[y]), cend(c[y]), x); ++it)
					ans[f(*it, y)] = true;
			else
				c.erase(y);
			x -= d;
		} else {
			if(!c[y].empty())
				for(auto it = upper_bound(cbegin(c[y]), cend(c[y]), x);
					it <= --upper_bound(cbegin(c[y]), cend(c[y]), x + d); ++it)
					ans[f(*it, y)] = true;
			else
				c.erase(y);
			x += d;
		}
	}
	cout << x << ' ' << y << ' ' << ans.count() << endl;
	return 0;
}
