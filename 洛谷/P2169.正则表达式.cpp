#include <iostream>
#include <utility>
#include <vector>
#include <bitset>
#include <stack>
#include <array>
#include <algorithm>
#include <ext/pb_ds/priority_queue.hpp>
using namespace std;

constexpr const int N = 200'003;
struct Query
{ int u, v, w; };
array<Query, N> query;
array<vector<pair<int, int>>, N> G;
bitset<N> ins, vis;
stack<int> stk;
array<int, N> dfn, low, bel, dis;
int idx = 0, cnt = 0;

void dfs(const int& u) {
	dfn[u] = low[u] = ++idx;
	stk.push(u);
	ins[u] = true;
	for(const auto& [v, _]: G[u])
		if(!dfn[v]) {
			dfs(v);
			low[u] = min(low[u], low[v]);
		} else if(ins[v])
			low[u] = min(low[u], dfn[v]);
	if(dfn[u] == low[u]) {
		++cnt;
		while(!stk.empty()) {
			int v = stk.top();
			stk.pop();
			ins[v] = false;
			bel[v] = cnt;
			if(v == u)
				break;
		}
	}
}

void Dijkstra(const int& s) {
	fill(dis.begin(), dis.end(), 0x3f3f3f3f);
	dis[s] = 0;
	__gnu_pbds::priority_queue<pair<int, int>, greater<>> q;
	q.push({dis[s], s});
	while(!q.empty()) {
		int u = q.top().second;
		q.pop();
		if(vis[u])
			continue;
		vis[u] = true;
		for(const auto& [v, w]: G[u])
			if(dis[u] + w < dis[v]) {
				dis[v] = dis[u] + w;
				q.push({dis[v], v});
			}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, m;
	cin >> n >> m;
	for(int i = 1, u, v, w; i <= m; ++i) {
		cin >> u >> v >> w;
		G[u].push_back({v, w});
		query[i] = {u, v, w};
	}
	dfs(1);
	for(auto& c: G)
		c.clear();
	for(int i = 1; i <= m; ++i) {
		auto [u, v, w] = query[i];
		if(bel[u] != bel[v])
			G[bel[u]].push_back({bel[v], w});
	}
	Dijkstra(bel[1]);
	cout << dis[bel[n]];
	cout.flush();
	return 0;
}