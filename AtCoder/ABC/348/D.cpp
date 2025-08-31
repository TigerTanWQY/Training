#include <iostream>
#include <cstring>
#include <utility>
#include <queue>
#include <algorithm>
using namespace std;

const int d[2][4]{{0, -1, 1, 0}, {-1, 0, 0, 1}};
const int N = 203;
char a[N][N];
int s[N][N], f[N][N];
int n, m, sx = 0, sy = 0;

void bfs() {
	memset(f, -1, sizeof(f));
	f[sx][sy] = 0;
	queue<pair<int, int>> q;
	q.push({sx, sy});
	while(!q.empty()) {
		int x = q.front().first, y = q.front().second;
		q.pop();
		const int r = max(f[x][y], s[x][y]);
		if(r <= 0)
			continue;
		for(int i = 0; i < 4; ++i) {
			int tx = x + d[0][i], ty = y + d[1][i];
			if(1 <= tx && tx <= n && 1 <= ty && ty <= m && a[tx][ty] != '#')
				if(f[tx][ty] < r - 1) {
					f[tx][ty] = r - 1;
					q.push({tx, ty});
				}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> m;
	int ex = 0, ey = 0;
	for(int i = 1; i <= n; ++i) {
		cin >> (a[i] + 1);
		for(int j = 1; j <= m; ++j)
			if(a[i][j] == 'S') {
				sx = i;
				sy = j;
			} else if(a[i][j] == 'T') {
				ex = i;
				ey = j;
			}
	}
	int k;
	cin >> k;
	for(int i = 1, x, y, r; i <= k; ++i) {
		cin >> x >> y >> r;
		s[x][y] = max(s[x][y], r);
	}
	bfs();
	if(~f[ex][ey])
		cout << "Yes";
	else
		cout << "No";
	return 0;
}