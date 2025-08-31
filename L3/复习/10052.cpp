#include <bits/stdc++.h>
using namespace std;

constexpr const int N = 4e5 + 3;
vector<pair<int, bool>> G[N];
int dis[N];

void bfs(const int rt) {
	memset(dis, 0x3f, sizeof(dis));
	dis[rt] = 0;
	deque<int> q;
	q.push_back(rt);
	while(!q.empty()) {
		int u = q.front();
		q.pop_front();
		for(const auto& [v, w]: G[u])
			if(dis[u] + w < dis[v]) {
				dis[v] = dis[u] + w;
				if(w)
					q.push_back(v);
				else
					q.push_front(v);
			}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, m, k;
	cin >> n >> m >> k;
	for(int u, v, w; m--; ) {
		cin >> u >> v >> w;
		if(w) {
			G[u].push_back({v, true});
			G[v].push_back({u, true});
		} else {
			G[u + n].push_back({v + n, true});
			G[v + n].push_back({u + n, true});
		}
	}
	for(int i = 1, s; i <= k; ++i) {
		cin >> s;
		G[s].push_back({s + n, false});
		G[s + n].push_back({s, false});
	}
	bfs(1);
	int ans = min(dis[n], dis[2 * n]);
	if(ans == 0x3f3f3f3f)
		ans = -1;
	cout << ans << endl;
	return 0;
}