#include <iostream>
#include <vector>
#include <utility>
#include <queue>
#include <algorithm>
using namespace std;

const int N = 50003;
vector<pair<int, int>> G[N];
bool vis[N];
int m = 0;
long long dis[N];

void SPFA(const int& root) {
	for(int i = 0; i <= m; ++i) {
		vis[i] = false;
		dis[i] = -0x3f3f3f3f;
	}
	dis[root] = 0;
	queue<int> q;
	q.push(root);
	vis[root] = true;
	while(!q.empty()) {
		int u = q.front();
		q.pop();
		vis[u] = false;
		for(const auto& p: G[u]) {
			int v = p.first, w = p.second;
			if(dis[u] + w > dis[v]) {
				dis[v] = dis[u] + w;
				if(!vis[v]) {
					q.push(v);
					vis[v] = true;
				}
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	for(int u, v, w; n--; ) {
		cin >> u >> v >> w;
		m = max({m, u, ++v});
		G[u].push_back({v, w});
		G[0].push_back({u, 0});
		G[0].push_back({v, 0});
	}
	for(int i = 1; i <= m; ++i) {
		G[i].push_back({i - 1, -1});
		G[i - 1].push_back({i, 0});
	}
	SPFA(0);
	cout << dis[m];
	return 0;
}