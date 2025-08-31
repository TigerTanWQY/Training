#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;
using PII = pair<int, int>;

vector<PII> a;
map<int, int> mp;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m;
	cin >> n >> m;
	for(int x, c; n--; ) {
		cin >> x >> c;
		if(mp.count(x))
			mp[x] += c;
		else
			mp[x] = c;
	}
	int tot = 0;
	for(const auto& x: mp) {
		a.push_back({x.first, tot});
		tot += x.second;
	}
	a.push_back({0x3f3f3f3f, tot});
	for(int L, R; m--; ) {
		cin >> L >> R;
		auto p1 = upper_bound(a.cbegin(), a.cend(), make_pair(L, -0x3f3f3f3f));
		auto p2 = upper_bound(a.cbegin(), a.cend(), make_pair(R, 0x3f3f3f3f));
		cout << p2->second - p1->second << '\n';
	}
	return 0;
}