#include <iostream>
#include <cstring>
#include <stack>
#include <queue>
#include <algorithm>
using namespace std;
using PII = pair<int, int>;

constexpr const int dxy[][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
constexpr const int N = 103;
struct Node
{ int x, y, id; };
stack<PII> stk;
bool vis[N][N];
char s[N][N];
int dfn[N][N], low[N][N], bel[N][N], f[N][N][4], idx, cnt, n, m, mx, my, px, py, kx, ky;
PII pts[N * N];

void dfs(int x, int y, int fx, int fy) {
	dfn[x][y] = low[x][y] = ++idx;
	stk.push({x, y});
	int son = 0;
	for(int i = 0; i < 4; ++i) {
		int tx = x + dxy[i][0], ty = y + dxy[i][1];
		if(tx < 1 || tx > n || ty < 1 || ty > m || s[tx][ty] == 'S')
			continue;
		if(!dfn[tx][ty]) {
			dfs(tx, ty, x, y);
			low[x][y] = min(low[x][y], low[tx][ty]);
			++son;
			if(low[tx][ty] >= dfn[x][y]) {
				bel[x][y] = ++cnt;
				pts[cnt] = {x, y};
				while(!stk.empty()) {
					auto [xx, yy] = stk.top();
					stk.pop();
					bel[xx][yy] = cnt;
					if(xx == tx && yy == ty)
						break;
				}
			}
		} else if(tx != fx || ty != fy)
			low[x][y] = min(low[x][y], dfn[tx][ty]);
	}
	if(!son && !fx && !fy)
		bel[x][y] = ++cnt;
}

void bfs() {
	memset(vis, 0, sizeof vis);
	vis[px][py] = true;
	queue<PII> q;
	q.push({mx, my});
	vis[mx][my] = true;
	while(!q.empty()) {
		auto [x, y] = q.front();
		q.pop();
		for(int i = 0; i < 4; ++i) {
			int tx = x + dxy[i][0], ty = y + dxy[i][1];
			if(tx < 1 || tx > n || ty < 1 || ty > m || s[tx][ty] == 'S' || vis[tx][ty])
				continue;
			vis[tx][ty] = true;
			q.push({tx, ty});
		}
	}
}

void solve() {
	cin >> n >> m;
	idx = cnt = 0;
	while(!stk.empty())
		stk.pop();
	for(int i = 1; i <= n; ++i) {
		cin >> (s[i] + 1);
		for(int j = 1; j <= m; ++j) {
			dfn[i][j] = low[i][j] = bel[i][j] = 0;
			if(s[i][j] == 'M') {
				mx = i;
				my = j;
			} else if(s[i][j] == 'P') {
				px = i;
				py = j;
			} else if(s[i][j] == 'K') {
				kx = i;
				ky = j;
			}
		}
	}
	for(int i = 1; i <= n; ++i)
		for(int j = 1; j <= m; ++j)
			if(s[i][j] != 'S' && !dfn[i][j])
				dfs(i, j, 0, 0);
	bfs();
	memset(f, -1, sizeof f);
	queue<Node> q[2];
	for(int i = 0; i < 4; ++i) {
		int tx = px + dxy[i][0], ty = py + dxy[i][1];
		if(tx < 1 || tx > n || ty < 1 || ty > m || !vis[tx][ty])
			continue;
		q[0].push({px, py, i});
		f[px][py][i] = 0;
	}
	while(!q[0].empty() || !q[1].empty()) {
		if(q[0].empty())
			swap(q[0], q[1]);
		auto [x, y, id] = q[0].front();
		q[0].pop();
		if(x == kx && y == ky) {
			cout << f[x][y][id];
			return;
		}
		int xx = x - dxy[id][0], yy = y - dxy[id][1];
		if(1 <= xx && xx <= n && 1 <= yy && yy <= m && s[xx][yy] != 'S' && !~f[xx][yy][id]) {
			f[xx][yy][id] = f[x][y][id] + 1;
			q[1].push({xx, yy, id});
		}
		xx = x + dxy[id][0];
		yy = y + dxy[id][1];
		for(int i = 0; i < 4; ++i)
			if(i != id) {
				int tx = x + dxy[i][0], ty = y + dxy[i][1];
				if(tx < 1 || tx > n || ty < 1 || ty > m || s[tx][ty] == 'S')
					continue;
				if(!~f[x][y][i] && (bel[xx][yy] == bel[tx][ty] || pts[bel[xx][yy]] == PII{tx, ty} || pts[bel[tx][ty]] == PII{xx, yy})) {
					f[x][y][i] = f[x][y][id];
					q[0].push({x, y, i});
				}
			}
	}
	cout << "NO";
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	solve();
	return 0;
}