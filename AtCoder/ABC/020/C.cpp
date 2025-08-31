#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/priority_queue.hpp>

constexpr const int dxy[4][3]{{0, -1}, {-1, 0}, {1, 0}, {0, 1}};
constexpr const int N = 13;
vector<pair<int, bool>> G[N * N];
bitset<N * N> vis;
char s[N][N];
int dis[N * N];

int main() {
	int n, m, T;
	scanf("%d%d%d", &n, &m, &T);
	int sx, sy, ex, ey;
	for(int i = 1; i <= n; ++i) {
		scanf("%s", s[i] + 1);
		for(int j = 1; j <= m; ++j)
			if(s[i][j] == 'S') {
				sx = i;
				sy = j;
			} else if(s[i][j] == 'G') {
				ex = i;
				ey = j;
			}
	}
	auto chg = [&m](const int& x, const int& y) -> int
	{ return (x - 1) * m + y - 1; };
	for(int i = 1; i <= n; ++i)
		for(int j = 1; j <= m; ++j)
			for(int k = 0; k < 4; ++k) {
				int tx = i + dxy[k][0], ty = j + dxy[k][1];
				if(1 <= tx && tx <= n && 1 <= ty && ty <= m)
					G[chg(i, j)].push_back({chg(tx, ty), s[tx][ty] == '#'});
			}
	for(int i = 0; i < n * m; ++i) {
		sort(begin(G[i]), end(G[i]));
		G[i].erase(unique(begin(G[i]), end(G[i])), cend(G[i]));
	}
	auto chk = [&](int w) -> bool {
		memset(dis, 0x3f, sizeof(dis));
		dis[chg(sx, sy)] = 0;
		__gnu_pbds::priority_queue<pair<int, int>, greater<>> q;
		q.push({dis[chg(sx, sy)], chg(sx, sy)});
		vis.reset();
		while(!q.empty()) {
			int u = q.top().second;
			q.pop();
			if(vis[u])
				continue;
			vis[u] = true;
			for(const auto& [v, tp]: G[u])
				if(tp) {
					if(dis[v] > dis[u] + w) {
						dis[v] = dis[u] + w;
						q.push({dis[v], v});
					}
				} else {
					if(dis[v] > dis[u] + 1) {
						dis[v] = dis[u] + 1;
						q.push({dis[v], v});
					}
				}
		}
		return dis[chg(ex, ey)] <= T;
	};
	int L = 0, R = 1e9 + 1;
	while(L + 1 < R) {
		int M = (L + R) >> 1;
		if(chk(M))
			L = M;
		else
			R = M;
	}
	printf("%d\n", L);
	return 0;
}
