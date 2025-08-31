#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

const int N = 303;
const int dt[2][4]{{0, -1, 1, 0}, {-1, 0, 0, 1}};
vector<pair<int, int>> ls;
char a[N][N];
int dis[N][N], d[N][N][N], dp[(1 << 18) + 3][21], H, W;

void bfs(const int &sx, const int &sy) {
	memset(dis, 0x3f, sizeof(dis));
	dis[sx][sy] = 0;
	queue<pair<int, int>> q;
	q.push({sx, sy});
	while(!q.empty()) {
		int x = q.front().first, y = q.front().second;
		q.pop();
		for(int k = 0; k < 4; ++k) {
			int tx = x + dt[0][k], ty = y + dt[1][k];
			if(0 <= tx && tx < H && 0 <= ty && ty < W && a[tx][ty] != '#' && dis[tx][ty] > dis[x][y] + 1) {
				dis[tx][ty] = dis[x][y] + 1;
				q.push({tx, ty});
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int T, sx, sy, gi, gj, ans = -1;
	cin >> H >> W >> T;
	for(int i = 0; i < H; ++i) {
		cin >> (a[i] + 0);
		for(int j = 0; j < W; ++j) {
			if(a[i][j] == 'S') {
				sx = i;
				sy = j;
			}
			if(a[i][j] == 'G') {
				gi = i;
				gj = j;
			}
			if(a[i][j] == 'o')
				ls.push_back({i, j});
		}
	}
	int m = ls.size();
	for(int i = 0; i < m; ++i) {
		bfs(ls[i].first, ls[i].second);
		memcpy(d[i], dis, sizeof(dis));
	}
	memset(dp, 0x3f, sizeof(dp));
	for(int i = 0; i < m; ++i)
		dp[1 << i][i] = d[i][sx][sy];
	for(int s = 1; s < (1 << m); ++s)
		for(int k = 0; k < m; ++k)
			if(dp[s][k] != 0x3f3f3f3f)
				for(int nx = 0; nx < m; ++nx) {
					if(s >> nx & 1)
						continue;
					dp[s | 1 << nx][nx] = min(dp[s | 1 << nx][nx], dp[s][k] + d[k][ls[nx].first][ls[nx].second]);
				}
	bfs(sx, sy);
	if(dis[gi][gj] <= T)
		ans = 0;
	for(int s = 1; s < (1 << m); ++s)
		for(int k = 0; k < m; ++k)
			if(dp[s][k] + d[k][gi][gj] <= T) {
				int now = 0;
				for(int i = 0; i < m; ++i)
					if(s >> i & 1)
						++now;
				ans = max(ans, now);
			}
	cout << ans;
	return 0;
}
