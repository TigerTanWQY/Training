#include <iostream>
#include <utility>
#include <vector>
#include <queue>
using namespace std;

const int N = 5003;
vector<pair<int, int>> G[N];
bool vis[N];
int d[N], cnt[N], n;

bool spfa(const int& root) {
	for(int i = 1; i <= n; ++i) {
		d[i] = 0x3f3f3f3f;
		vis[i] = false;
		cnt[i] = 0;
	}
	d[root] = 0;
	vis[root] = true;
	++cnt[root];
	queue<int> q;
	q.push(root);
	while(!q.empty()) {
		int u = q.front();
		q.pop();
		vis[u] = false;
		for(const auto& p: G[u]) {
			int v = p.first, w = p.second;
			if(d[v] > d[u] + w) {
				d[v] = d[u] + w;
				if(!vis[v]) {
					vis[v] = true;
					q.push(v);
					++cnt[v];
					if(cnt[v] > n + 1)
						return true;
				}
			}
		}
	}
	return false;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int m;
	cin >> n >> m;
	for(int u, v, w; m--; ) {
		cin >> u >> v >> w;
		G[v].push_back({u, w});
	}
	for(int i = 1; i <= n; ++i)
		G[0].push_back({i, 0});
	if(!spfa(0))
		for(int i = 1; i <= n; ++i)
			cout << d[i] << ' ';
	else
		cout << "NO";
	return 0;
}