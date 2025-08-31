#include <iostream>
#include <string>
#include <vector>
#include <bitset>
#include <stack>
#include <array>
#include <algorithm>
using namespace std;

class BigO {
private:
	static constexpr const int N = 53;
	array<vector<int>, N> G, subG, scc;
	stack<int> stk;
	bitset<N> ins;
	array<int, N> low, dfn, bel, f;
	int idx = 0, cnt = 0;
	void dfs(const int& u) {
		low[u] = dfn[u] = ++idx;
		stk.push(u);
		ins[u] = true;
		for(const auto& v: G[u])
			if(!dfn[v]) {
				dfs(v);
				low[u] = min(low[u], low[v]);
			} else if(ins[v])
				low[u] = min(low[u], dfn[v]);
		if(low[u] == dfn[u]) {
			++cnt;
			while(!stk.empty()) {
				int v = stk.top();
				stk.pop();
				ins[v] = false;
				scc[cnt].push_back(v);
				if(v == u)
					break;
			}
		}
	}
	bitset<N> vis;
	bool check(const int& u) {
		vis[u] = true;
		for(const auto& v: G[u])
			if(!vis[v])
				return check(v);
			else
				return true;
		return false;
	}
public:
	int minK(string str[]) {
		int n = str->size(), m = str[0].size();
		for(int i = 1; i <= n; ++i)
			for(int j = 0; j < m; ++j)
				if(str[i][j] == 'N')
					G[i].push_back(j);
		for(int u = 1; u <= n; ++u)
			if(!dfn[u])
				dfs(u);
		int res = 0;
		for(int i = 1; i <= cnt; ++i) {
			sort(scc[i].begin(), scc[i].end());
			for(const auto& u: scc[i])
				for(const auto& v: G[u]) {
					auto cit = lower_bound(scc[i].cbegin(), scc[i].cend(), v);
					if(cit != scc[i].cend() && *cit == v)
						subG[u].push_back(v);
				}
			if(check(1)) {
				cout << "-1";
				return 0;
			}
			vis.reset();
			f[i] = 0;
			for(const auto& u: scc[i])
				for(const auto& v: G[u])
					if(!vis[bel[v]] && bel[v] != i) {
						vis[bel[v]] = true;
						if(f[bel[v]] > f[v])
							f[v] = f[bel[v]];
					}
			f[i] += scc[i].size();
			res = max(res, f[i]);
			vis.reset();
		}
		return res - 1;
	}
};