#include <bits/stdc++.h>
using namespace std;
using LL = long long;

constexpr const int N = 2e5 + 3;
vector<pair<int, int>> G[N];
bitset<N> vis;
int a[N], b[N];
LL dis[N];
#include <ext/pb_ds/priority_queue.hpp>

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, m, k;
	cin >> n >> m >> k;
	for(int u, v, w; m--; ) {
		cin >> u >> v >> w;
		G[u].push_back({v, w});
		G[v].push_back({u, w});
	}
	for(int i = 1; i <= k; ++i)
		cin >> a[i];
	for(int i = 1; i <= k; ++i)
		cin >> b[i];
	sort(b + 1, b + k + 1);
	auto Dijkstra = [](int s, int t) -> LL {
		memset(dis, 0x3f, sizeof(dis));
		dis[s] = 0;
		__gnu_pbds::priority_queue<pair<LL, int>, greater<>> q;
		q.push({dis[s], s});
		vis.reset();
		while(!q.empty()) {
			int u = q.top().second;
			q.pop();
			if(vis[u])
				continue;
			vis[u] = true;
			if(u == t)
				break;
			for(const auto& [v, w]: G[u])
				if(dis[v] > dis[u] + w) {
					dis[v] = dis[u] + w;
					q.push({dis[v], v});
				}
		}
		return dis[t];
	};
	LL ans = 0x3f3f3f3f3f3f3f3f;
	do {
		LL tot = 0;
		for(int i = 1; i <= k; ++i)
			tot += Dijkstra(a[i], b[i]);
		ans = min(ans, tot);
	} while(next_permutation(b + 1, b + k + 1));
	cout << ans << endl;
	return 0;
}
