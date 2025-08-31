#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;

constexpr const int N = 2e4 + 3;
vector<int> G[N];
int dis[N];

void bfs(const int rt) {
	memset(dis, 0, sizeof(dis));
	dis[rt] = 1;
	queue<int> q;
	q.push(rt);
	while(!q.empty()) {
		int u = q.front();
		q.pop();
		for(const auto& v: G[u])
			if(!dis[v]) {
				dis[v] = dis[u] + 1;
				q.push(v);
			}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, m, q;
	cin >> n >> m >> q;
	for(int u, v; m--; ) {
		cin >> u >> v;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	for(int u, v; q--; cout.put('\n')) {
		cin >> u >> v;
		bfs(u);
		if(dis[v])
			cout << dis[v] - 1;
		else
			cout << "-1";
	}
	cout.flush();
	return 0;
}