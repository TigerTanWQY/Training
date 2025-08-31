#include <iostream>
#include <utility>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

const int N = 10003;
vector<pair<int, int>> G[N];
int d[N], n;

void bfs(const int& root) {
	for(int i = 1; i <= n; ++i)
		d[i] = 0;
	d[root] = 1;
	queue<int> q;
	q.push(root);
	while(!q.empty()) {
		int u = q.front();
		q.pop();
		for(const auto& p: G[u]) {
			int v = p.first, w = p.second;
			if(!d[v]) {
				d[v] = d[u] + w;
				q.push(v);
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	for(int _ = 1, u, v, w; _ < n; ++_) {
		cin >> u >> v >> w;
		G[u].push_back({v, w});
		G[v].push_back({u, w});
	}
	int ans = -1e9;
	for(int u = 1; u <= n; ++u) {
		bfs(u);
		for(int v = 1; v <= n; ++v)
			if(u != v)
				ans = max(ans, d[v]);
	}
	cout << ans - 1;
	return 0;
}