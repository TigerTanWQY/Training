#include <iostream>
#include <unordered_map>
#include <vector>
#include <utility>
#include <stack>
using namespace std;

const int N = 503;
unordered_map<int, vector<pair<int, int>>> G;
bool vis[N];
int dis[N], cnt[N], n;

bool SPFA(const int& root) {
	for(int i = 0; i <= n; ++i) {
		vis[i] = false;
		dis[i] = 0x3f3f3f3f;
		cnt[i] = 0;
	}
	dis[root] = 0;
	stack<int> q;
	q.push(root);
	vis[root] = true;
	++cnt[root];
	while(!q.empty()) {
		int u = q.top();
		q.pop();
		vis[u] = false;
		for(const auto& p: G[u]) {
			int v = p.first, w = p.second;
			if(dis[u] + w < dis[v]) {
				dis[v] = dis[u] + w;
				if(!vis[v]) {
					q.push(v);
					vis[v] = true;
					if(++cnt[v] > n + 1)
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
	int _T;
	cin >> _T;
	for(int m, k; _T--; ) {
		cin >> n >> m >> k;
		for(int u, v, w; m--; ) {
			cin >> u >> v >> w;
			G[u].push_back({v, w});
			G[v].push_back({u, w});
		}
		for(int u, v, w; k--; ) {
			cin >> u >> v >> w;
			G[u].push_back({v, -w});
		}
		for(int v = 1; v <= n; ++v)
			G[0].push_back({v, 0});
		if(SPFA(0))
			cout << "YES";
		else
			cout << "NO";
		cout << '\n';
		G.clear();
	}
	return 0;
}