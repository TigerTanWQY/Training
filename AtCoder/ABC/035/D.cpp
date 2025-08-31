#include <bits/stdc++.h>
using namespace std;
using LL = long long;

constexpr const int N = 1e5 + 3;
vector<pair<int, int>> G[2][N];
bitset<N> vis;
int a[N], n;
LL dis[2][N];
#include <ext/pb_ds/priority_queue.hpp>

auto Dijkstra = [](int tp) -> void {
	auto& g = G[tp]; auto& d = dis[tp];
	memset(d, 0x3f, sizeof(LL) * (n + 2));
	d[1] = 0;
	__gnu_pbds::priority_queue<pair<LL, int>, greater<>> q;
	q.push({d[1], 1});
	vis.reset();
	while(!q.empty()) {
		int u = q.top().second;
		q.pop();
		if(vis[u])
			continue;
		vis[u] = true;
		for(const auto& [v, w]: g[u])
			if(d[v] > d[u] + w) {
				d[v] = d[u] + w;
				q.push({d[v], v});
			}
	}
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int m, T;
	cin >> n >> m >> T;
	for(int i = 1; i <= n; ++i)
		cin >> a[i];
	for(int u, v, w; m--; ) {
		cin >> u >> v >> w;
		G[0][u].push_back({v, w});
		G[1][v].push_back({u, w});
	}
	Dijkstra(0); Dijkstra(1);
	LL ans = 0;
	for(int i = 1; i <= n; ++i)
		if(dis[0][i] != 0x3f3f3f3f3f3f3f3f && dis[1][i] != 0x3f3f3f3f3f3f3f3f)
			ans = max(ans, a[i] * (T - dis[0][i] - dis[1][i]));
	cout << ans << endl;
	return 0;
}
