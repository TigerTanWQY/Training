#include <bits/stdc++.h>
using namespace std;

const vector<pair<int, int>> DIR = {
	{0, -1}, {0, 1}, {-1, 0}, {1, 0}
};
vector<vector<int>> CONV {
	{0, 1, 2, 3},
	{2, 3, 0, 1},
	{3, 2, 1, 0}
};
void solve() {
	int n, m;
	cin >> n >> m;
	vector<string> v(n);
	for(int i = 0; i < n; ++i) {
		cin >> v[i];
	}
	vector dp(n, vector(m, vector<int>(4, n * m + 1)));
	deque<array<int, 4>> q;
	q.push_front({0, -1, 1, 0});
	while(!q.empty()) {
		auto [x, y, idx, dis] = q.front();
		q.pop_front();
		auto [dx, dy] = DIR[idx];
		int xx = x + dx, yy = y + dy;
		if(xx < 0 || xx >= n || yy < 0 || yy >= m) continue;
		for(auto ch : string("ABC")) {
			int nidx = CONV[ch - 'A'][idx];
			int ndis = dis + (ch != v[xx][yy]);
			if(ndis < dp[xx][yy][nidx]) {
				if(ch == v[xx][yy]) {
					q.push_front({xx, yy, nidx, ndis});
				} else {
					q.push_back({xx, yy, nidx, ndis});
				}
				dp[xx][yy][nidx] = ndis;
			}
		}
	}
	cout << dp[n - 1][m - 1][1] << '\n';
}

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int T;
	cin >> T;
	while(T--) {
		solve();
	}
	return 0;
}
