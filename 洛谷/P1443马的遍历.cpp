#include <iostream>
#include <cstring>
#include <utility>
#include <queue>
using namespace std;

const int d[2][8]{{-1, 1, -2, 2, -2, 2, -1, 1}, {-2, -2, -1, -1, 1, 1, 2, 2}};
const int N = 403;
bool vis[N][N];
int f[N][N];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m, x, y;
	cin >> n >> m >> x >> y;
	memset(f, -1, sizeof(f));
	queue<pair<int, int>> q;
	q.push({x, y});
	vis[x][y] = true;
	f[x][y] = 0;
	while(!q.empty()) {
		x = q.front().first, y = q.front().second;
		q.pop();
		for(int k = 0; k < 8; ++k) {
			int tx = x + d[0][k], ty = y + d[1][k];
			if(1 <= tx && tx <= n && 1 <= ty && ty <= m && !vis[tx][ty]) {
				vis[tx][ty] = true;
				f[tx][ty] = f[x][y] + 1;
				q.push({tx, ty});
			}
		}
	}
	for(int i = 1; i <= n; ++i) {
		for(int j = 1; j <= m; ++j)
			cout << f[i][j] << ' ';
		cout << '\n';
	}
	return 0;
}