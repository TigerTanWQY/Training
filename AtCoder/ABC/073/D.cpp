#include <bits/stdc++.h>
using namespace std;

constexpr const int N = 203;
vector<pair<int, int>> G[N];
bitset<N> vis;
int dis[8][N], r[8], p[8], n;
#include <ext/pb_ds/priority_queue.hpp>

auto Dijkstra = [](int id) -> void {
	auto& d = dis[id]; int rt = r[id];
	memset(d, 0x3f, sizeof(int) * (n + 2));
	d[rt] = 0;
	__gnu_pbds::priority_queue<pair<int, int>, greater<>> q;
	q.push({d[rt], rt});
	vis.reset();
	while(!q.empty()) {
		int u = q.top().second;
		q.pop();
		if(vis[u])
			continue;
		vis[u] = true;
		for(const auto& [v, w]: G[u])
			if(d[v] > d[u] + w) {
				d[v] = d[u] + w;
				q.push({d[v], v});
			}
	}
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int m, k;
	cin >> n >> m >> k;
	for(int i = 0; i < k; ++i)
		cin >> r[i];
	for(int u, v, w; m--; ) {
		cin >> u >> v >> w;
		G[u].push_back({v, w});
		G[v].push_back({u, w});
	}
	sort(r, r + k);
	for(int i = 0; i < k; ++i) {
		Dijkstra(i);
		p[i] = i;
	}
	int ans = 0x3f3f3f3f;
	do {
		int tot = 0;
		for(int i = 0; i < k - 1; ++i)
			tot += dis[p[i]][r[p[i + 1]]];
		ans = min(ans, tot);
	} while(next_permutation(p, p + k));
	cout << ans << endl;
	return 0;
}
