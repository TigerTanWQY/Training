#include <bits/stdc++.h>
using namespace std;

constexpr const int dx[]{-1, 1, 0, 0}, dy[]{0, 0, -1, 1};
constexpr const int N = 503;
bool vis[N][N];
int a[N][N];

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	for(int i = 0; i < n; ++i)
		for(int j = 0; j < m; ++j)
			cin >> a[i][j];
	unordered_set<string> st;
	for(int i = 0; i < n; ++i)
		for(int j = 0; j < m; ++j) {
			if(vis[i][j])
				continue;
			queue<pair<int, int>> q;
			q.push({i, j});
			vis[i][j] = true;
			vector<pair<int, int>> pts;
			pts.push_back({i, j});
			int col = a[i][j];
			while(!q.empty()) {
				auto [x, y] = q.front();
				q.pop();
				for(int d = 0; d < 4; ++d) {
					int tx = x + dx[d], ty = y + dy[d];
					if(tx >= 0 && tx < n && ty >= 0 && ty < m && !vis[tx][ty] && a[tx][ty] == col) {
						vis[tx][ty] = true;
						q.push({tx, ty});
						pts.push_back({tx, ty});
					}
				}
			}
			auto [minX, minY] = pts[0];
			for(const auto &[x, y]: pts) {
				minX = min(minX, x);
				minY = min(minY, y);
			}
			vector<pair<int, int>> rlt;
			for(const auto &[x, y]: pts)
				rlt.push_back({x - minX, y - minY});
			sort(rlt.begin(), rlt.end());
			string key;
			for(const auto &[x, y]: rlt)
				key += to_string(x) + "," + to_string(y) + " ";
			if(!key.empty())
				key.pop_back();
			st.insert(key);
		}
	cout << st.size() << endl;
	return 0;
}
