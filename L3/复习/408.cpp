#include <iostream>
#include <queue>
using namespace std;

constexpr const int dxy[4][3]{{0, -1}, {-1, 0}, {1, 0}, {0, 1}};
constexpr const int N = 1003;
char a[N][N];
int dis[N][N], n, m;

void bfs(const int sx, const int sy) {
	dis[sx][sy] = 1;
	queue<pair<int, int>> q;
	q.push({sx, sy});
	while(!q.empty()) {
		auto [x, y] = q.front();
		q.pop();
		for(int k = 0; k < 4; ++k) {
			int tx = x + dxy[k][0], ty = y + dxy[k][1];
			if(1 <= tx && tx <= n && 1 <= ty && ty <= m && a[tx][ty] != 'X' && !dis[tx][ty]) {
				dis[tx][ty] = dis[x][y] + 1;
				q.push({tx, ty});
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n >> m;
	int sx, sy, ex, ey;
	for(int i = 1; i <= n; ++i) {
		cin >> (a[i] + 1);
		for(int j = 1; j <= m; ++j)
			if(a[i][j] == 'S') {
				sx = i;
				sy = j;
			} else if(a[i][j] == 'E') {
				ex = i;
				ey = j;
			}
	}
	bfs(sx, sy);
	cout << dis[ex][ey] - 1 << endl;
	return 0;
}