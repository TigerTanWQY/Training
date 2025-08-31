#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
using namespace std;

const int MOD = 998244353;
vector<pair<int, int>> a;
set<pair<int, int>> s;
map<pair<long long, long long>, int> f;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, m, ans = 0;
	cin >> n >> m;
	for(int _ = 0, x, y; _ < 3; ++_) {
		cin >> x >> y;
		a.push_back({x, y});
	}
	for(int x, y; m--; ) {
		cin >> x >> y;
		s.insert({x, y});
	}
	f[{0, 0}] = 1;
	for(int i = 0; i < n; ++i) {
		map<pair<long long, long long>, int> tmp;
		for(const auto &p: f) {
			const auto &x = p.first.first, &y = p.first.second;
			for(const auto &q: a)
				if(s.find({x + q.first, y + q.second}) == s.cend())
					tmp[{x + q.first, y + q.second}] = (tmp[{x + q.first, y + q.second}] + p.second) % MOD;
		}
		swap(f, tmp);
	}
	for(const auto &p: f)
		ans = (ans + p.second) % MOD;
	cout << ans;
	return 0;
}