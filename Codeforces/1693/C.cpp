#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
#include <utility>
using namespace std;
using PII = pair<int, int>;
#define w first
#define u second

const int N = 200003;
vector<int> G[N];
bool vis[N];
int d[N], dis[N];

void Dijkstra(const int& p) {
//	memset(vis, 0, sizeof(vis));
	memset(dis, 0x3f, sizeof(dis));
	dis[p] = 0;
	priority_queue<PII, vector<PII>, greater<PII>> q;
	q.push({0, p});
	while(!q.empty()) {
		int u = q.top().u, w = q.top().w;
		q.pop();
		if(vis[u])
			continue;
		vis[u] = true;
		dis[u] = w;
		for(const auto& v: G[u]) {
			if(!vis[v])
				q.push({dis[u] + d[v], v});
			--d[v];
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m;
	cin >> n >> m;
	for(int u, v; m--; ) {
		cin >> u >> v;
		G[v].push_back(u);
		++d[u];
	}
	Dijkstra(n);
	cout << dis[1];
	return 0;
}