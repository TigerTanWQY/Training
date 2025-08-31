#include <iostream>
#include <map>
#include <algorithm>
using namespace std;
using LL = long long;

constexpr const int P = 998244353;
map<pair<LL, LL>, int> f;
pair<LL, LL> a[3], st[100003];

inline void add(int& x, const int y)
{ x += y; x %= P; }

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, m;
	cin >> n >> m;
	for(int i = 0; i < 3; ++i)
		cin >> a[i].first >> a[i].second;
	for(int i = 0, x, y; i < m; ++i) {
		cin >> x >> y;
		st[i] = {x, y};
	}
	sort(st, st + m);
	f[{0, 0}] = 1;
	for(int _ = 0; _ < n; ++_) {
		map<pair<LL, LL>, int> tmp;
		for(const auto& p: f) {
			const auto& [x, y] = p.first;
			for(const auto &q: a) {
				pair<LL, LL> tp = {x + q.first, y + q.second};
				auto cit = lower_bound(st, st + m, tp);
				if(cit == st + m || *cit != tp)
					add(tmp[tp], p.second);
			}
		}
		swap(f, tmp);
	}
	int ans = 0;
	for(const auto &p: f)
		add(ans, p.second);
	cout << ans << endl;
	return 0;
}