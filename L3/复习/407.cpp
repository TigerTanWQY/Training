#include <iostream>
#include <cstring>
#include <vector>
#include <deque>
using namespace std;

constexpr const int N = 2e4 + 3;
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
			if(dis[v] > dis[u] + w) {
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
	int n, m, q;
	cin >> n >> m >> q;
	for(int u, v, w; m--; ) {
		cin >> u >> v >> w;
		G[u].push_back({v, w});
		G[v].push_back({u, w});
	}
	for(int u, v; q--; cout.put('\n')) {
		cin >> u >> v;
		bfs(u);
		if(dis[v] >= 0x3f3f3f3f / 2)
			cout << "-1";
		else
			cout << dis[v];
	}
	cout.flush();
	return 0;
}