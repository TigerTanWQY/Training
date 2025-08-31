#include <bits/stdc++.h>
using namespace std;

constexpr const int dxy[4][3]{{0, -1}, {-1, 0}, {1, 0}, {0, 1}};
constexpr const int N = 1003;
char s[N][N];
int dis[N][N];

int main() {
	int n, m, d;
	scanf("%d%d%d", &n, &m, &d);
	for(int i = 1; i <= n; ++i)
		scanf("%s", s[i] + 1);
	auto bfs = [&n, &m](void) {
		memset(dis, 0, sizeof(dis));
		queue<pair<int, int>> q;
		for(int i = 1; i <= n; ++i)
			for(int j = 1; j <= m; ++j)
				if(s[i][j] == 'H') {
					dis[i][j] = 1;
					q.push({i, j});
				}
		while(!q.empty()) {
			auto [x, y] = q.front();
			q.pop();
			for(int i = 0; i < 4; ++i) {
				int tx = x + dxy[i][0], ty = y + dxy[i][1];
				if(1 <= tx && tx <= n && 1 <= ty && ty <= m && s[tx][ty] != '#' && !dis[tx][ty]) {
					dis[tx][ty] = dis[x][y] + 1;
					q.push({tx, ty});
				}
			}
		}
	};
	bfs();
	int ans = 0;
	for(int i = 1; i <= n; ++i)
		for(int j = 1; j <= m; ++j)
			if(dis[i][j] && dis[i][j] - 1 <= d)
				++ans;
	printf("%d\n", ans);
	return 0;
}
