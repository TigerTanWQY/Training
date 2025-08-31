#include <bits/stdc++.h>
#include <ext/pb_ds/priority_queue.hpp>
using namespace std;
using LL = long long;

constexpr const int N = 1e4 + 3, K = 103;
vector<pair<int, int>> G[N];
bool vis[N][K];
int k;
LL dis[N][K];

void Dijkstra(LL rt) {
	memset(dis, 0x3f, sizeof(dis));
	dis[rt][0] = 0;
	__gnu_pbds::priority_queue<pair<LL, int>, greater<>> q;
	q.push({dis[rt][0], rt});
	memset(vis, 0, sizeof(vis));
	while(!q.empty()) {
		auto [p, u] = q.top();
		q.pop();
		if(vis[u][p % k])
		  continue;
		vis[u][p % k] = true;
		for(const auto& [v, w]: G[u]) {
			LL t = (p + 1) % k;
			if(p >= w)
				t = p;
			else
				t = ((w - p + k - 1) / k) * k + p;
			if(dis[v][(t + 1) % k] > t + 1) {
				dis[v][(t + 1) % k] = t + 1;
				q.push({t + 1, v});
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, m;
	cin >> n >> m >> k;
	for(int u, v, w; m--; ) {
		cin >> u >> v >> w;
		G[u].push_back({v, w});
	}
	Dijkstra(1);
	if(!vis[n][0])
		dis[n][0] = -1;
	cout << dis[n][0] << endl;
	return 0;
}