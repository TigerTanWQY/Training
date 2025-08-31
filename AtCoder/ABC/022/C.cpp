#include <bits/stdc++.h>
using namespace std;

constexpr const int N = 303;
bitset<N> vis;
int G[N][N], dis[N], n;

#include <ext/pb_ds/priority_queue.hpp>
void Dijkstra() {
	memset(dis, 0x3f, sizeof(dis));
	dis[1] = 0;
	__gnu_pbds::priority_queue<pair<int, int>, greater<>> q;
	q.push({dis[1], 1});
	vis.reset();
	while(!q.empty()) {
		int u = q.top().second;
		q.pop();
		if(vis[u])
			continue;
		vis[u] = true;
		for(int v = 1; v <= n; ++v)
			if(G[u][v] && dis[v] > dis[u] + G[u][v]) {
				dis[v] = dis[u] + G[u][v];
				q.push({dis[v], v});
			}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int m;
	cin >> n >> m;
	for(int u, v, w; m--; ) {
		cin >> u >> v >> w;
		G[u][v] = G[v][u] = w;
	}
	int ans = 0x3f3f3f3f;
	for(int i = 2; i <= n; ++i)
		if(G[1][i]) {
			G[1][i] = 0;
			Dijkstra();
			G[1][i] = G[i][1];
			ans = min(ans, dis[i] + G[i][1]);
		}
	if(ans == 0x3f3f3f3f)
		cout << "-1";
	else
		cout << ans;
	cout << endl;
	return 0;
}
