#include <iostream>
#include <vector>
#include <bitset>
#include <queue>
using namespace std;

constexpr const int N = 2e5 + 3;
vector<int> G[N];
bitset<N> vis;
int dis[N], ans = -1;

void bfs(const int rt) {
	queue<int> q;
	q.push(rt);
	vis[rt] = true;
	while(!~ans && !q.empty()) {
		int u = q.front();
		q.pop();
		for(const auto& v: G[u])
			if(v == 1) {
				ans = dis[u] + 1;
				break;
			} else if(!vis[v]) {
				dis[v] = dis[u] + 1;
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
	}
	bfs(1);
	cout << ans << endl;
	return 0;
}