#include <bits/stdc++.h>
using namespace std;

constexpr const int dxy[2][2][2]{{{-1, 0}, {1, 0}}, {{0, -1}, {0, 1}}};
constexpr const int N = 1003;
char s[N][N];
int dist[2][N][N], n, m;

void bfs(int sx, int sy, int tp) {
	auto& dis = dist[tp];
	memset(dis, 0, sizeof(dis));
	dis[sx][sy] = 1;
	queue<tuple<int, int, bool>> q;
	q.push({sx, sy, tp});
	while(!q.empty()) {
		auto [x, y, dir] = q.front();
		q.pop(); dir = !dir;
		for(int i = 0; i < 2; ++i) {
			int tx = x + dxy[dir][i][0], ty = y + dxy[dir][i][1];
			if(1 <= tx && tx <= n && 1 <= ty && ty <= m && s[tx][ty] != '#' && !dis[tx][ty]) {
				dis[tx][ty] = dis[x][y] + 1;
				q.push({tx, ty, dir});
			}
		}
	}
}

int main() {
	scanf("%d%d", &n, &m);
	int sx = 0, sy = 0, ex = 0, ey = 0;
	for(int i = 1; i <= n; ++i) {
		scanf("%s", s[i] + 1);
		for(int j = 1; j <= m; ++j)
			if(s[i][j] == 'S')
			{ sx = i; sy = j; }
			else if(s[i][j] == 'G')
			{ ex = i; ey = j; }
	}
	bfs(sx, sy, 0);
	bfs(sx, sy, 1);
	int ans = 0x3f3f3f3f;
	if(dist[0][ex][ey])
		ans = min(ans, dist[0][ex][ey]);
	if(dist[1][ex][ey])
		ans = min(ans, dist[1][ex][ey]);
	if(ans == 0x3f3f3f3f)
		puts("-1");
	else
		printf("%d\n", ans - 1);
	return 0;
}
