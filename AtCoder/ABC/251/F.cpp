#include <iostream>
#include <vector>
#include <bitset>
#include <queue>
using namespace std;

const int N = 200'003;
vector<int> G[N];
bitset<N> vis;

void dfs(const int& u) {
	vis[u] = true;
	for(const auto& v: G[u])
		if(!vis[v]) {
			cout << u << ' ' << v << '\n';
			dfs(v);
		}
}

void bfs(const int& s) {
	queue<int> q;
	q.push(s);
	vis[s] = true;
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
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, m;
	cin >> n >> m;
	for(int u, v; m--; ) {
		cin >> u >> v;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	dfs(1);
	vis = 0;
	bfs(1);
	cout.flush();
	return 0;
}