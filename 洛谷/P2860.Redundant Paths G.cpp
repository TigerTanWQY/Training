#include <iostream>
#include <utility>
#include <vector>
#include <bitset>
#include <stack>
#include <algorithm>
using namespace std;
#define _u first
#define _v second

constexpr const int N = 5'003;
constexpr const int M = 20'003;
vector<vector<int>> eDCC;
vector<pair<int, int>> G[N];
stack<int> stk;
bitset<N> vis;
bitset<M> ins;
pair<int, int> e[M];
int dep[N], low[N], bel[N], d[N], cnt = 0;

void dfs(const int& u, const int& fa) {
	dep[u] = low[u] = dep[fa] + 1;
	stk.push(u);
	vis[u] = true;
	for(const auto& [v, id]: G[u]) {
		if(ins[id])
			continue;
		else
			ins[id] = true;
		if(!dep[v]) {
			dfs(v, u);
			low[u] = min(low[u], low[v]);
		} else if(vis[v])
			low[u] = min(low[u], dep[v]);
	}
	if(dep[u] == low[u]) {
		++cnt;
		while(!stk.empty()) {
			int v = stk.top();
			stk.pop();
			bel[v] = cnt;
			if(v == u)
				break;
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, m;
	cin >> n >> m;
	for(int i = 1; i <= m; ++i) {
		cin >> e[i]._u >> e[i]._v;
		G[e[i]._u].push_back({e[i]._v, i});
		G[e[i]._v].push_back({e[i]._u, i});
	}
	for(int u = 1; u <= n; ++u)
		if(!vis[u])
			dfs(u, 0);
	for(int i = 1; i <= m; ++i)
		if(bel[e[i]._u] != bel[e[i]._v]) {
			++d[bel[e[i]._u]];
			++d[bel[e[i]._v]];
		}
	int ans = 0;
	for(int i = 1; i <= cnt; ++i)
		if(d[i] == 1)
			++ans;
	cout << (ans + 1 >> 1);
	cout.flush();
	return 0;
}