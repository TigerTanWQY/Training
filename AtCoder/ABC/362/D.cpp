#include <iostream>
#include <cstring>
#include <utility>
#include <vector>
#include <queue>
using namespace std;
using LL = long long;

const int N = 200003;
vector<pair<int, int>> G[N];
bool vis[N];
int a[N];
LL dis[N];

void Dijkstra(const int& s) {
	memset(dis, 0x3f, sizeof(dis));
	dis[s] = a[s];
	priority_queue<pair<LL, int>, vector<pair<LL, int>>, greater<>> q;
	q.push({dis[s], s});
	while(!q.empty()) {
		int u = q.top().second;
		q.pop();
		if(vis[u])
			continue;
		vis[u] = true;
		for(const auto& [v, w]: G[u])
			if(dis[u] + w + a[v] < dis[v]) {
				dis[v] = dis[u] + w + a[v];
				q.push({dis[v], v});
			}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m;
	cin >> n >> m;
	for(int i = 1; i <= n; ++i)
		cin >> a[i];
	for(int u, v, w; m--; ) {
		cin >> u >> v >> w;
		G[u].push_back({v, w});
		G[v].push_back({u, w});
	}
	Dijkstra(1);
	for(int i = 2; i <= n; ++i)
		cout << dis[i] << ' ';
	cout << endl;
	return 0;
}