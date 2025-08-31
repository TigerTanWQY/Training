#include <iostream>
#include <vector>
#include <bitset>
#include <stack>
#include <array>
#include <algorithm>
using namespace std;

constexpr const int N = 1'003;
vector<vector<int>> vDCC;
array<vector<int>, N> G, subG;
bitset<N> vis;
stack<int> stk;
array<int, N> low, dfn, col;
int idx;

void tarjan(const int& u, const int& fau) {
	int child = 0;
	low[u] = dfn[u] = ++idx;
	stk.push(u);
	for(const auto& v: G[u]) {
		if(!dfn[v]) {
			++child;
			tarjan(v, u);
			low[u] = min(low[u], low[v]);
			if(low[v] >= dfn[u]) {
				vector<int> c{u};
				while(!stk.empty()) {
					int x = stk.top();
					stk.pop();
					c.push_back(x);
					if(x == v)
						break;
				}
				vDCC.push_back(c);
			}
		} else if(v != fau)
			low[u] = min(low[u], dfn[v]);
	}
	if(fau == 0 && child == 0)
		vDCC.push_back({u});
}

bool dfs(const int& u, const int& c) {
	col[u] = c;
	for(const auto& v: subG[u])
		if(!col[v]) {
			if(dfs(v, 3 - c))
				return true;
		} else if(col[v] == c)
			return true;
	return false;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	for(int n, m; cin >> n >> m && (n || m); ) {
		for(int u, v; m--; ) {
			cin >> u >> v;
			G[u].push_back(v);
			G[v].push_back(u);
		}
		for(int u = 1; u <= n; ++u)
			if(!dfn[u]) {
				tarjan(u, 0);
				for(; !stk.empty(); stk.pop());
			}
		for(auto& c: vDCC) {
			sort(c.begin(), c.end());
			for(const auto& u: c)
				for(const auto& v: G[u]) {
					auto cit = lower_bound(c.cbegin(), c.cend(), v);
					if(cit != c.cend() && *cit == v) {
						subG[u].push_back(v);
						subG[v].push_back(u);
					}
				}
			bool flag = true;
			for(int u = 1; flag && u <= n; ++u)
				if(!col[u])
					if(dfs(u, 1))
						flag = false;
			if(!flag)
				for(const auto& u: c)
					vis[u] = true;
			subG.fill({});
			col.fill({});
		}
		cout << vis.count() << '\n';
		idx = 0;
		low.fill({});
		dfn.fill({});
		G.fill({});
		vDCC.clear();
		vis.reset();
	}
	cout.flush();
	return 0;
}