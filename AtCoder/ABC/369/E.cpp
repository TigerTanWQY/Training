#include <iostream>
#include <cstring>
#include <vector>
#include <bitset>
#include <ext/pb_ds/priority_queue.hpp>
using namespace std;
using LL = long long;

constexpr const int N = 403;
struct Edge
{ int u, v, w; }
e[200'003];
vector<pair<int, int>> G[N];
bitset<N> vis;
int b[6], k;
LL dis[N];

void Dijkstra(const int rt) {
	memset(dis, 0x3f, sizeof(dis));
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
			if(dis[u] + w < dis[v]) {
				dis[v] = dis[u] + w;
				q.push({dis[v], v});
			}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, m, q;
	cin >> n >> m;
	for(int i = 1, u, v, w; i <= m; ++i) {
		cin >> u >> v >> w;
		G[u].push_back({v, w});
		G[v].push_back({u, w});
		e[i] = {u, v, w};
	}
	cin >> q;
	for(; q--; cout.put('\n')) {
		cin >> k;
		for(int i = 1; i <= k; ++i)
			cin >> b[i];
		Dijkstra(1);
		cout << dis[n];
	}
	cout.flush();
	return 0;
}