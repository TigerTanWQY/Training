#include <bits/stdc++.h>
using namespace std;

constexpr const int N = 2e5 + 3;
vector<int> G[N];
bool vis[N];

void dfs(int u) {
	vis[u] = true;
	for(const auto& v: G[u])
		if(!vis[v]) {
			cout << u << ' ' << v << '\n';
			dfs(v);
		}
}

void bfs(int rt) {
	queue<int> q;
	q.push(rt);
	vis[rt] = true;
	while(!q.empty()) {
		int u = q.front();
		q.pop();
		for(const auto& v: G[u])
			if(!vis[v]) {
				cout << u << ' ' << v << '\n';
				q.push(v);
				vis[v] = true;
			}
	}
}

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	for(int u, v; m--; ) {
		cin >> u >> v;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	dfs(1);
	memset(vis, 0, sizeof vis);
	bfs(1);
	cout.flush(); return 0;
}
