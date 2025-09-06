#include <bits/stdc++.h>
using namespace std;

constexpr const int dxy[][2]{{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
constexpr const int N = 1003;
char G[N][N];
int dis[N][N];

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int n, m, sx, sy, ex, ey;
	cin >> n >> m;
	for(int i = 0; i < n; ++i)
		for(int j = 0; j < m; ++j)
			cin >> G[i][j];
	cin >> sx >> sy >> ex >> ey;
	sx--; sy--; ex--; ey--;
	memset(dis, -1, sizeof(dis));
	dis[sx][sy] = 0;
	queue<pair<int, int>> q;
	q.push({sx, sy});
	while(!q.empty()) {
		auto [x, y] = q.front();
		q.pop();
		for(int i = 0; i < 4; ++i) {
			int tx = x + dxy[i][0], ty = y + dxy[i][1];
			if(tx >= 0 && tx < n && ty >= 0 && ty < m && G[tx][ty] == '.' && dis[tx][ty] == -1) {
				dis[tx][ty] = 0;
				q.push({tx, ty});
			}
		}
	}
	if(~dis[ex][ey]) {
		cout << '0' << endl;
		return 0;
	}
	for(int k = 0; ; ++k) {
		vector<pair<int, int>> a;
		for(int i = 0; i < n; ++i)
			for(int j = 0; j < m; ++j)
				if(dis[i][j] == k)
					a.push_back({i, j});
		if(a.empty()) {
			cout << "-1" << endl;
			return 0;
		}
		for(const auto& [x, y]: a)
			for(int i = 0; i < 4; ++i) {
				int tx = x, ty = y;
				for(int _ = 2; _--; ) {
					tx += dxy[i][0]; ty += dxy[i][1];
					if(tx < 0 || tx >= n || ty < 0 || ty >= m)
						break;
					if(G[tx][ty] == '#')
						G[tx][ty] = '.';
				}
			}
		queue<pair<int, int>> q2;
		for(const auto& p: a)
			q2.push(p);
		bool flag = false;
		while(!q2.empty()) {
			auto [x, y] = q2.front();
			q2.pop();
			for(int i = 0; i < 4; ++i) {
				int tx = x + dxy[i][0], ty = y + dxy[i][1];
				if(tx >= 0 && tx < n && ty >= 0 && ty < m && G[tx][ty] == '.' && dis[tx][ty] == -1) {
					dis[tx][ty] = k + 1;
					q2.push({tx, ty});
					if(tx == ex && ty == ey)
						flag = true;
				}
			}
		}
		if(flag) {
			cout << k + 1 << endl;
			return 0;
		}
	}
	return 0;
}
