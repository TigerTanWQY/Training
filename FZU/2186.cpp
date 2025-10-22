#include <bits/stdc++.h>
using namespace std;

constexpr const int dxy[][4]{{0, -1, 1, 0}, {-1, 0, 0, 1}};
constexpr const int N = 103, K = 11;
struct Node
{ int x, y, z; };
bool vis[N][N];
int dis[K][K], f[1<<K][K], G[N][N], n, m;

void bfs(int sx, int sy, int sz) {
	queue<Node> q;
	q.push({sx, sy, 0});
	memset(vis, 0, sizeof vis);
	vis[sx][sy] = 1;
	while(!q.empty()) {
		auto [x, y, z] = q.front();
		q.pop();
		if(G[x][y] > 0)
			dis[sz][G[x][y]] = z;
		for(int i = 0; i < 4; ++i)
			if(0 <= x && x < n && 0 <= y && y < m && !vis[x][y] && G[x][y] >= 0) {
				vis[x][y] = true;
				q.push({x + dxy[0][i], y + dxy[1][i], z + 1});
			}
	}
}

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	for(; cin >> n >> m; cout.put('\n')) {
		int cnt = 0;
		for(int i = 0; i < n; ++i)
			for(int j = 0; j < m; ++j){
				cin >> G[i][j];
				if(G[i][j] > 0 && i + j)
					G[i][j] = ++cnt;
			}
		if(G[0][0] < 0) {
			cout << "-1";
			continue;
		} else if(!cnt) {
			cout << "0";
			continue;
		}
		G[0][0] = 0;
		for(auto& c: dis)
			for(auto& i: c)
				i = 1e9;
		bfs(0, 0, 0);
		for(int i = 0; i < n; ++i)
			for(int j = 0; j < m; ++j)
				if(G[i][j] > 0)
					bfs(i, j, G[i][j]);
		int tot = 1 << cnt;
		for(auto& c: f)
			for(auto& i: c)
				i = 1e9;
		for(int i = 1; i < tot; ++i)
			for(int j = 0; j < cnt; ++j)
				if(i & 1 << j) {
					int l = i - (1 << j);
					if(l == 0) {
						f[i][j + 1] = dis[0][j + 1];
						continue;
					}
					for(int k = 0; k < cnt; ++k)
						if(l & 1 << k)
							f[i][j + 1] = min(f[i][j + 1], f[l][k + 1] + dis[k + 1][j + 1]);
				}
		int ans = 1e9;
		for(int i = 1; i <= cnt; ++i)
			ans = min(ans, f[tot - 1][i] + dis[0][i]);
		if(ans == 1e9)
			cout << "-1";
		else
			cout << ans;
	}
	cout.flush(); return 0;
}
