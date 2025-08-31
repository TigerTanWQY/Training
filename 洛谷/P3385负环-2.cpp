#include <iostream>
#include <utility>
#include <vector>
#include <unordered_map>
#include <queue>
using namespace std;

const int N = 2003;
unordered_map<int, vector<pair<int, int>>> G;
bool vis[N];
int d[N], cnt[N], n;

bool SPFA() {
	for(int i = 1; i <= n; ++i) {
		vis[i] = false;
		d[i] = 0x3f3f3f3f;
		cnt[i] = 0;
	}
	d[1] = 0;
	vis[1] = true;
	++cnt[1];
	queue<int> q;
	q.push(1);
	while(!q.empty()) {
		int u = q.front();
		q.pop();
		vis[u] = false;
		for(const auto &p: G[u]) {
			int v = p.first, w = p.second;
			if(d[u] + w < d[v]) {
				d[v] = d[u] + w;
				if(!vis[v]) {
					q.push(v);
					++cnt[v];
					vis[v] = true;
				}
				if(cnt[v] > n)
					return true;
			}
		}
	}
	return false;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int T;
	cin >> T;
	for(int m; T--; ) {
		cin >> n >> m;
		for(int u, v, w; m--; ) {
			cin >> u >> v >> w;
			G[u].push_back({v, w});
			if(w >= 0)
				G[v].push_back({u, w});
		}
		if(SPFA())
			cout << "YES";
		else
			cout << "NO";
		cout << '\n';
		G.clear();
	}
	return 0;
}