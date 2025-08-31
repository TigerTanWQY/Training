#include <iostream>
#include <utility>
#include <queue>
#include <array>
#include <set>
using namespace std;

constexpr const int N = 200'003;
array<set<pair<int, int>>, N> G;
array<pair<int, int>, N> fa;
array<int, N> dis;

void bfs(const int root) {
	dis.fill(0);
	dis[root] = 1;
	queue<int> q;
	q.push(root);
	while(!q.empty()) {
		int u = q.front();
		q.pop();
		for(const auto& [v, w]: G[u])
			if(!dis[v]) {
				dis[v] = dis[u] + w;
				fa[v] = {u, w};
				q.push(v);
			}
	}
}

//void dfs(const int u, const int fau) {
//	;
//}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	cin >> n;
	for(int _ = 1, u, v, w; _ < n; ++_) {
		cin >> u >> v >> w;
		G[u].insert({v, w});
		G[v].insert({u, w});
	}
	int u = 1;
	bfs(u);
	for(int i = 2; i <= n; ++i)
		if(dis[i] > dis[u])
			u = i;
	bfs(u);
	int v = 1;
	for(int i = 2; i <= n; ++i)
		if(dis[i] > dis[v])
			v = i;
	cout << dis[v] - 1 << '\n';
//	cout << v << ' ' << u << '\n';
	int maxn = 0, maxi = 0;
	for(int i = v; i != u; i = fa[i].first) {
//		cout << i << ' ';
		G[i].erase({fa[i].first, fa[i].second});
		G[fa[i].first].erase({i, fa[i].second});
//		dfs(i, 0);
	}
//	cout << u << '\n';
	;
	cout.flush();
	return 0;
}