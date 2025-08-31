#include <iostream>
#include <vector>
#include <bitset>
#include <map>
#include <algorithm>
using namespace std;

constexpr const int N = 200003;
map<int, vector<pair<int, int>>> a[2];
bitset<N * 2> ans;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n1, n2;
	cin >> n1 >> n2;
	for(int i = 1, x, y; i <= n1; ++i) {
		cin >> x >> y;
		a[0][x].push_back({y, i});
		a[1][y].push_back({x, i});
	}
	for(int i = 1, x, y; i <= n2; ++i) {
		cin >> x >> y;
		a[0][x].push_back({y, n1 + i});
		a[1][y].push_back({x, n1 + i});
	}
	for(int _ = 0; _ < 2; ++_)
		for(auto& [__, p]: a[_]) {
			sort(p.begin(), p.end());
			for(int i = 1; i < p.size(); ++i)
				if((p[i - 1].second <= n1 && p[i].second > n1) || (p[i - 1].second > n1 && p[i].second <= n1))
					ans[p[i - 1].second] = ans[p[i].second] = true;
		}
	for(int i = 1; i <= n1; ++i)
		cout.put('0' + ans[i]);
	cout.put('\n');
	for(int i = 1; i <= n2; ++i)
		cout.put('0' + ans[n1 + i]);
	cout << endl;
	return 0;
}