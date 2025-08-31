#include <bits/stdc++.h>
using namespace std;
using LL = long long;

constexpr const int dxy[4][3]{{0, -1}, {-1, 0}, {1, 0}, {0, 1}};
constexpr const int N = 503;
bool vis[N][N];
LL a[N][N];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, m, k, sx, sy;
	cin >> n >> m >> k >> sx >> sy;
	for(int i = 1; i <= n; ++i)
		for(int j = 1; j <= m; ++j)
			cin >> a[i][j];
	LL ans = 0;
	queue<pair<int, int>> q1, q2;
	vis[sx][sy] = true;
	q1.push({sx, sy});
	while(!q1.empty()) {
		auto [x, y] = q1.front();
		q1.pop();
		ans += a[x][y];
		bool ok = true;
		for(int i = 0; i < 4; ++i) {
			int tx = x + dxy[i][0], ty = y + dxy[i][1];
			if(1 <= tx && tx <= n && 1 <= ty && ty <= m && !vis[tx][ty])
				if(a[tx][ty] < 1.0 * ans / k) {
					q1.push({tx, ty});
					vis[tx][ty] = true;
					ok = false;
				}
		}
		if(ok)
			q1.push({x, y});
	}
	cout << ans << endl;
	return 0;
}
