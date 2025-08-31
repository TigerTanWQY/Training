#include <iostream>
#include <bitset>
#include <array>
#include <queue>
#include <algorithm>
using namespace std;

constexpr const int dxy[][4]{{0, -1, 1, 0}, {-1, 0, 0, 1}};
constexpr const int N = 103;
constexpr const int K = 11;
struct Node
{ int x, y, step; };
array<bitset<N>, N> vis;
array<array<int, K>, K> dis;
array<array<int, K>, 1 << K> f;
array<array<int, N>, N> G;
int n, m;


void bfs(const int& x, const int& y, const int& z) {
	queue<Node> q;
	q.push({x, y, 0});
	vis.fill({});
	vis[x][y] = 1;
	while(!q.empty()) {
		auto u = q.front();
		q.pop();
		if(G[u.x][u.y] > 0)
			dis[z][G[u.x][u.y]] = u.step;
		for(int i = 0; i < 4; ++i) {
			Node v{u.x + dxy[0][i], u.y + dxy[1][i], u.step + 1};
			if(0 <= v.x && v.x < n && 0 <= v.y && v.y < m && !vis[v.x][v.y] && G[v.x][v.y] >= 0) {
				vis[v.x][v.y] = true;
				q.push(v);
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	while(cin >> n >> m) {
		int cnt = 0;
		for(int i = 0; i < n; ++i)
			for(int j = 0; j < m; ++j){
				cin >> G[i][j];
				if(G[i][j] > 0 && i + j)
					G[i][j] = ++cnt;
			}
		if(G[0][0] < 0) {
			cout << "-1\n";
			continue;
		} else if(!cnt) {
			cout << "0\n";
			continue;
		}
		G[0][0] = 0;
		for(auto& c: dis)
			for(auto& i: c)
				i = 0x3f3f3f3f;
		bfs(0, 0, 0);
		for(int i = 0; i < n; ++i)
			for(int j = 0; j < m; ++j)
				if(G[i][j] > 0)
					bfs(i, j, G[i][j]);
		int tot = 1 << cnt;
		for(auto& c: f)
			for(auto& i: c)
				i = 0x3f3f3f3f;
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
		int ans = 0x3f3f3f3f;
		for(int i = 1; i <= cnt; ++i)
			ans = min(ans, f[tot - 1][i] + dis[0][i]);
		if(ans == 0x3f3f3f3f)
			cout << "-1\n";
		else
			cout << ans << '\n';
	}
	return 0;
}