#include <iostream>
#include <vector>
#include <bitset>
#include <queue>
#include <array>
#include <algorithm>
using namespace std;

constexpr const int N = 200'003;
array<vector<int>, N> G;
array<int, N> dis, fa, dep;
bitset<N> vis;
int maxd;

void bfs(const int root) {
	dis.fill(0);
	dis[root] = 1;
	queue<int> q;
	q.push(root);
	while(!q.empty()) {
		int u = q.front();
		q.pop();
		for(const auto& v: G[u])
			if(!dis[v]) {
				dis[v] = dis[u] + 1;
				fa[v] = u;
				q.push(v);
			}
	}
}

void dfs(const int u) {
	vis[u] = true;
	for(const auto& v: G[u])
		if(!vis[v]) {
			dep[v] = dep[u] + 1;
			dfs(v);
		}
	maxd = max(maxd, dep[u]);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	cin >> n;
	for(int _ = 1, u, v; _ < n; ++_) {
		cin >> u >> v;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	int u = 1, v = 1;
	bfs(u);
	for(int i = 2; i <= n; ++i)
		if(dis[i] > dis[u])
			u = i;
	bfs(u);
	for(int i = 2; i <= n; ++i)
		if(dis[i] > dis[v])
			v = i;
	for(const auto& x: G[u])
		vis[x] = true;
	for(const auto& x: G[v])
		vis[x] = true;
	int ans = 0, cnt = 0, c = 0;
	for(int i = v; i != u; i = fa[i]) {
		++ans;
		vis[fa[i]] = true;
		dep[i] = 1;
		dfs(i);
		if(dep[i] > cnt && i != v && i != u) {
			cnt = dep[i];
			c = i;
		}
		dep.fill({});
		maxd = 0;
	}
	dep[u] = 1;
	dfs(u);
	if(dep[u] > cnt)
		cnt = dep[u];
//	dep.fill({});
//	maxd = 0;
	cout << ans + cnt << '\n' << u << ' ' << v << ' ' << c;
	cout.flush();
	return 0;
}