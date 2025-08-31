#include <iostream>
#include <cstring>
#include <vector>
#include <bitset>
#include <algorithm>
#include <ext/pb_ds/priority_queue.hpp>
using namespace std;
using TIII = tuple<int, int, int>;

constexpr const int d[4][3]{{0, -1}, {-1, 0}, {1, 0}, {0, 1}};
constexpr const int N = 103;
vector<TIII> G[N][N];
bitset<N> vis[N];
int a[N][N], dis[N][N];

void Dijkstra(const int sx, const int sy) {
	memset(dis, 0x3f, sizeof(dis));
	dis[sx][sy] = 0;
	__gnu_pbds::priority_queue<TIII, greater<TIII>> q;
	q.push({dis[sx][sy], sx, sy});
	while(!q.empty()) {
		auto [_, x, y] = q.top();
		q.pop();
		if(vis[x][y])
			continue;
		vis[x][y] = true;
		for(const auto& [tx, ty, w]: G[x][y])
			if(dis[tx][ty] > dis[x][y] + w) {
				dis[tx][ty] = dis[x][y] + w;
				q.push({dis[tx][ty], tx, ty});
			}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, k;
	cin >> n >> k;
	memset(a, -1, sizeof(a));
	for(int x, y, c; k--; ) {
		cin >> x >> y >> c;
		a[x][y] = c;
	}
	for(int i = 1; i <= n; ++i)
		for(int j = 1; j <= n; ++j)
			for(k = 0; k < 4; ++k) {
				int tx = i + d[k][0], ty = j + d[k][1];
				if(1 > tx || tx > n || 1 > ty || ty > n)
					continue;
				if(~a[i][j] && ~a[tx][ty]) {
					G[i][j].push_back({tx, ty, a[tx][ty] != a[i][j]});
					G[tx][ty].push_back({i, j, a[tx][ty] != a[i][j]});
				} else if(~a[i][j]) {
					G[i][j].push_back({tx, ty, 2});
				}
			}
	for(int i = 1; i <= n; ++i)
		for(int j = 1; j <= n; ++j) {
			sort(G[i][j].begin(), G[i][j].end());
			G[i][j].erase(unique(G[i][j].begin(), G[i][j].end()), G[i][j].cend());
		}
	Dijkstra(1, 1);
	if(dis[n][n] == 0x3f3f3f3f)
		dis[n][n] = -1;
	cout << dis[n][n] << endl;
	return 0;
}