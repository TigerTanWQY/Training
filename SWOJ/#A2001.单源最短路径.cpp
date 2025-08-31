#include <iostream>
#include <cstring>
#include <vector>
#include <bitset>
#include <ext/pb_ds/priority_queue.hpp>
using namespace std;
using LL = long long;

constexpr const int N = 150'003;
vector<pair<int, int>> G[N];
bitset<N> vis;
LL dis[N];

void Dijkstra(const int rt) {
	memset(dis, 0x3f, sizeof(dis));
	dis[rt] = 0;
	__gnu_pbds::priority_queue<pair<int, int>, greater<>> q;
	q.push({dis[rt], rt});
	while(!q.empty()) {
		int u = q.top().second;
		q.pop();
		if(vis[u])
			continue;
		vis[u] = true;
		for(const auto& [v, w]: G[u])
			if(dis[u] + w < dis[v]) {
				dis[v] = dis[u] + w;
				q.push({dis[v], v});
			}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, m, s, t;
	cin >> n >> m >> s >> t;
	for(int u, v, w; m--; ) {
		cin >> u >> v >> w;
		G[u].push_back({v, w});
		G[v].push_back({u, w});
	}
	Dijkstra(s);
	cout << dis[t];
	cout.flush();
	return 0;
}