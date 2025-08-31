#include <bits/stdc++.h>
using namespace std;

constexpr const int N = 1e5 + 3;
vector<int> G[N];
int dis[N];

void bfs(const int rt) {
	memset(dis, -1, sizeof(dis));
	dis[rt] = 0;
	queue<int> q;
	q.push(rt);
	while(!q.empty()) {
		int u = q.front();
		q.pop();
		for(const auto& v: G[u])
			if(!~dis[v]) {
				dis[v] = dis[u] + 1;
				q.push(v);
			}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, q;
	cin >> n >> q;
	for(int _ = 1, u, v; _ < n; ++_) {
		cin >> u >> v;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	bfs(1);
	for(int u, v; q--; cout.put('\n')) {
		cin >> u >> v;
		if((dis[u] & 1) ^ (dis[v] & 1))
			cout << "Road";
		else
			cout << "Town";
	}
	cout.flush();
	return 0;
}
