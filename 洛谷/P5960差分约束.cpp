#include <bits/stdc++.h>
using namespace std;

constexpr const int N = 5003;
vector<pair<int, int>> G[N];
bool vis[N];
int d[N], cnt[N], n;

bool SPFA(int rt) {
	for(int i = 1; i <= n; ++i) {
		d[i] = 0x3f3f3f3f;
		vis[i] = false;
		cnt[i] = 0;
	}
	d[rt] = 0;
	queue<int> q;
	q.push(rt);
	vis[rt] = true; ++cnt[rt];
	while(!q.empty()) {
		int u = q.front(); q.pop();
		vis[u] = false;
		for(const auto& [v, w]: G[u])
			if(d[v] > d[u] + w) {
				d[v] = d[u] + w;
				if(!vis[v]) {
					vis[v] = true;
					q.push(v);
					++cnt[v];
					if(cnt[v] >= n)
						return true;
				}
			}
	}
	return false;
}

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int m;
	cin >> n >> m;
	for(int u, v, w; m--; ) {
		cin >> u >> v >> w;
		G[v].push_back({u, w});
	}
	for(int i = 1; i <= n; ++i)
		G[0].push_back({i, 0});
	if(!SPFA(0))
		for(int i = 1; i <= n; ++i)
			cout << d[i] << ' ';
	else
		cout << "NO";
	cout << endl; return 0;
}
