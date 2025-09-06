#include <bits/stdc++.h>
using namespace std;

constexpr const int dxy[][2]{{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
constexpr const int N = 503;
char a[N][N];
int dis[N][N][2];

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	for(int i = 0; i < n; ++i)
		cin >> a[i];
	int sx = -1, sy = -1, ex = -1, ey = -1;
	for(int i = 0; i < n; ++i)
		for(int j = 0; j < m; ++j)
			if(a[i][j] == 'S') {
				sx = i;
				sy = j;
			} else if(a[i][j] == 'G') {
				ex = i;
				ey = j;
			}
	memset(dis, 0x3f, sizeof dis);
	dis[sx][sy][0] = 0;
	queue<tuple<int, int, bool>> q;
	q.push({sx, sy, 0});
	while(!q.empty()) {
		auto [x, y, w] = q.front();
		q.pop();
		if(x == ex && y == ey) {
			cout << dis[x][y][w] << endl;
			return 0;
		}
		for(int i = 0; i < 4; ++i) {
			int tx = x + dxy[i][0], ty = y + dxy[i][1];
			if(tx < 0 || tx >= n || ty < 0 || ty >= m)
				continue;
			const char& ch = a[tx][ty];
			if(ch == '#' || (ch == 'o' && w) || (ch == 'x' && !w))
				continue;
			bool tw = w;
			if(ch == '?')
				tw = w ^ 1;
			if(dis[x][y][w] + 1 < dis[tx][ty][tw]) {
				dis[tx][ty][tw] = dis[x][y][w] + 1;
				q.push({tx, ty, tw});
			}
		}
	}
	cout << "-1" << endl;
	return 0;
}
