#include <iostream>
#include <vector>
#include <array>
#include <algorithm>
using namespace std;
using LL = long long;

const int N = 2003;
vector<array<int, 5>> op;
vector<int> c[2];
LL a[N][N];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m, q;
	cin >> n >> m >> q;
	for(int x1, y1, x2, y2, d; q--; ) {
		cin >> x1 >> y1 >> x2 >> y2 >> d;
		op.push_back({x1, y1, x2, y2, d});
		c[0].push_back(x1 - 1);
		c[0].push_back(x2);
		c[1].push_back(y1 - 1);
		c[1].push_back(y2);
	}
	sort(c[0].begin(), c[0].end());
	c[0].erase(unique(c[0].begin(), c[0].end()), c[0].cend());
	sort(c[1].begin(), c[1].end());
	c[1].erase(unique(c[1].begin(), c[1].end()), c[1].cend());
	for(auto [x1, y1, x2, y2, d]: op) {
		x1 = lower_bound(c[0].cbegin(), c[0].cend(), x1 - 1) - c[0].cbegin() + 1;
		x2 = lower_bound(c[0].cbegin(), c[0].cend(), x2) - c[0].cbegin();
		y1 = lower_bound(c[1].cbegin(), c[1].cend(), y1 - 1) - c[1].cbegin() + 1;
		y2 = lower_bound(c[1].cbegin(), c[1].cend(), y2) - c[1].cbegin();
		a[x1][y1] += d;
		a[x1][y2 + 1] -= d;
		a[x2 + 1][y1] -= d;
		a[x2 + 1][y2 + 1] += d;
	}
	n = c[0].size();
	m = c[1].size();
	for(int i = 1; i <= n; ++i)
		for(int j = 1; j <= m; ++j)
			a[i][j] += a[i][j - 1];
	for(int i = 1; i <= n; ++i)
		for(int j = 1; j <= m; ++j)
			a[i][j] += a[i - 1][j];
	LL ans = 0;
	for(int i = 1; i < n; ++i)
		for(int j = 1; j < m; ++j) {
			LL k = 1LL * (c[0][i] - c[0][i - 1]) * (c[1][j] - c[1][j - 1]);
			if(k & 1)
				ans ^= a[i][j];
		}
	cout << ans;
	cout << endl;
	return 0;
}