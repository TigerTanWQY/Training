#include <iostream>
#include <unordered_set>
#include <vector>
#include <bitset>
#include <algorithm>
#include <functional>
using namespace std;
using PII = pair<int, int>;

unordered_set<int> G[1003][1003];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int H, W, n, m, k;
	cin >> H >> W >> n >> m >> k;
	for(int i = 1, x, y, p, q; i <= k; ++i) {
		cin >> x >> y >> p >> q;
		G[x][y].insert(i);
		G[p][q].insert(i);
	}
	vector<PII> a;
	vector<int> ans;
	for(int i = 1; i < H; ++i) {
		int cnt = 0;
		for(int j = 1; j <= W; ++j)
			for(const auto& x: G[i][j])
				for(const auto& y: G[i + 1][j])
					if(x == y)
						++cnt;
		a.push_back({cnt, i});
	}
	sort(a.begin(), a.end(), greater<PII>());
	if(n == 0)
		cout.put('0');
	else {
		for(int i = 0; i < n; ++i)
			ans.push_back(a[i].second);
		sort(ans.begin(), ans.end());
		for(const auto& x: ans)
			cout << x << ' ';
	}
	cout.put('\n');
	a.clear();
	ans.clear();
	for(int j = 1; j < W; ++j) {
		int cnt = 0;
		for(int i = 1; i <= H; ++i)
			for(const auto& x: G[i][j])
				for(const auto& y: G[i][j + 1])
					if(x == y)
						++cnt;
		a.push_back({cnt, j});
	}
	sort(a.begin(), a.end(), greater<PII>());
	if(m == 0)
		cout.put('0');
	else {
		for(int i = 0; i < m; ++i)
			ans.push_back(a[i].second);
		sort(ans.begin(), ans.end());
		for(const auto& x: ans)
			cout << x << ' ';
	}
	cout << endl;
	return 0;
}