#include <bits/stdc++.h>
using namespace std;

constexpr const int INF = 1024, N = 1003;
vector<pair<int, int>> G[N];
bitset<INF> vis[N];

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	for(int u, v, w; m--; ) {
		cin >> u >> v >> w;
		G[u].push_back({v, w});
	}
	queue<pair<int, int>> q;
	q.push({1, 0});
	vis[1][0] = true;
	while(!q.empty()) {
		auto [u, s] = q.front();
		q.pop();
		for(const auto& [v, w]: G[u]) {
			int ts = s ^ w;
			if(!vis[v][ts]) {
				vis[v][ts] = true;
				q.push({v, ts});
			}
		}
	}
	int ans = -1;
	for(int s = 0; s < INF; ++s)
		if(vis[n][s])
			if(!~ans || s < ans)
				ans = s;
	cout << ans << endl;
	return 0;
}
