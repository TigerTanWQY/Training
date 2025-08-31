#include <bits/stdc++.h>
using namespace std;
using LL = long long;

constexpr const LL INF = 1e9;
constexpr const int N = 3e3 + 3;
vector<pair<int, LL>> G[N];
bitset<N> vis;
int cnt[N], n;
LL h[N], dis[N];

bool SPFA(int rt) {
	memset(cnt, 0, sizeof(cnt));
	memset(h, 0x3f, sizeof(h));
	h[rt] = 0;
	queue<int> q;
	q.push(rt);
	vis.reset();
	vis[rt] = true;
	while(!q.empty()) {
		int u = q.front();
		q.pop();
		vis[u] = false;
		for(const auto& [v, w]: G[u])
			if(h[v] > h[u] + w) {
				h[v] = h[u] + w;
				if(!vis[v]) {
					q.push(v);
					vis[v] = true;
					if(++cnt[v] == n + 1)
						return true;
				}
			}
	}
	return false;
}
#include <ext/pb_ds/priority_queue.hpp>
void Dijkstra(int rt) {
	for(int i = 1; i <= n; ++i)
		dis[i] = INF;
	dis[rt] = 0;
	__gnu_pbds::priority_queue<pair<LL, int>, greater<>> q;
	q.push({dis[rt], rt});
	vis.reset();
	while(!q.empty()) {
		int u = q.top().second;
		q.pop();
		if(vis[u])
			continue;
		vis[u] = true;
		for(const auto& [v, w]: G[u])
			if(dis[v] > dis[u] + w) {
				dis[v] = dis[u] + w;
				if(!vis[v])
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
		G[u].push_back({v, w});
	}
	for(int i = 1; i <= n; ++i)
		G[0].push_back({i, 0});
	if(SPFA(0)) {
		cout << "-1" << endl;
		return 0;
	}
	for(int u = 1; u <= n; ++u)
		for(auto& [v, w]: G[u])
			w += h[u] - h[v];
	for(int u = 1; u <= n; ++u) {
		Dijkstra(u);
		LL ans = 0;
		for(int v = 1; v <= n; ++v)
			if(dis[v] == INF)
				ans += v * INF;
			else
				ans += v * (dis[v] + h[v] - h[u]);
		cout << ans << '\n';
	}
	cout.flush();
	return 0;
}
