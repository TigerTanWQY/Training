#include <iostream>
#include <cstring>
#include <utility>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
using LL = long long;

constexpr const int N = 200'003;
vector<pair<int, int>> G[N];
LL dis[N], bak[N];

void bfs(const int rt) {
	memset(dis, 0, sizeof(dis));
	dis[rt] = 1;
	queue<int> q;
	q.push(rt);
	while(!q.empty()) {
		int u = q.front();
		q.pop();
		for(const auto& [v, w]: G[u])
			if(!dis[v]) {
				dis[v] = dis[u] + w;
				q.push(v);
			}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m;
	cin >> n >> m;
	for(int u, v, w; m--; ) {
		cin >> u >> v >> w;
		G[u].push_back({v, w});
		G[v].push_back({u, w});
	}
	bfs(1);
	int u = 1;
	for(int i = 2; i <= n; ++i)
		if(dis[i] > dis[u])
			u = i;
	bfs(u);
	int v = 1;
	for(int i = 2; i <= n; ++i)
		if(dis[i] > dis[v])
			v = i;
	LL ans = dis[v];
	memcpy(bak, dis, sizeof(dis));
	bfs(v);
	LL k = 0;
	for(int i = 1; i <= n; ++i)
		k = max(k, min(dis[i], bak[i]));
	cout << ans + k - 2;
	cout.flush();
	return 0;
}