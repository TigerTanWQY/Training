#include <bits/stdc++.h>
using namespace std;

constexpr const int dxy[][2]{{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
constexpr const int N = 103;
bool vis[N][N];
char a[N][N];
int n, m;

void bfs(int sx, int sy) {
	queue<pair<int, int>> q;
	q.push({sx, sy});
	while(!q.empty()) {
		auto [x, y] = q.front();
		q.pop();
		if(vis[x][y])
			continue;
		vis[x][y] = true;
		for(int i = 0; i < 4; ++i) {
			int tx = x + dxy[i][0], ty = y + dxy[i][1];
			if(/*1 <= tx && tx <= n && 1 <= ty && ty <= m && */a[tx][ty] == '.' && !vis[tx][ty])
				q.push({tx, ty});
		}
	}
}

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	cin >> n >> m;
	for(int i = 1; i <= n; ++i)
		for(int j = 1; j <= m; ++j)
			cin >> a[i][j];
	bfs(1, 1);
	cout << (vis[n][m]? "Yes": "No") << endl;
	return 0;
}
