#include <iostream>
#include <cstring>
#include <vector>
#include <deque>
#include <algorithm>
using namespace std;
#define v first
#define w second

const int N = 400003;
vector<pair<int, bool>> G[N];
int dist[N];

void bfs(const int& root) {
	deque<int> q;
	memset(dist, 0x3f, sizeof(dist));
	q.push_back(root);
	dist[root] = 0;
	while(!q.empty()) {
		int u = q.front();
		q.pop_front();
		for(const auto& p: G[u])
			if(dist[u] + p.w < dist[p.v]) {
				dist[p.v] = dist[u] + p.w;
				if(p.w)
					q.push_back(p.v);
				else
					q.push_front(p.v);
			}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
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
	int ans = min(dist[n], dist[2 * n]);
	if(ans == 0x3f3f3f3f)
		cout << "-1";
	else
		cout << ans;
	return 0;
}