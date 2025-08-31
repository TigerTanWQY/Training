#include <iostream>
#include <utility>
#include <vector>
#include <bitset>
#include <stack>
#include <array>
#include <map>
#include <unordered_map>
#include <algorithm>
using namespace std;

constexpr const int N = 300'003;
map<pair<int, int>, int> id;
unordered_map<int, vector<int>> r, c;
unordered_map<int, int> rid, cid;
array<vector<int>, N> G;
bitset<N> ins;
stack<int> stk;
array<int, N> x, y, ty, dfn, low, bel, f;
int n, idx = 0, cnt = 0, ans = 0;

void dfs(const int& u) {
	dfn[u] = low[u] = ++idx;
	stk.push(u);
	ins[u] = true;
	for(const auto& v: G[u])
		if(!dfn[v]) {
			dfs(v);
			low[u] = min(low[u], low[v]);
		} else if(ins[v])
			low[u] = min(low[u], dfn[v]);
	if(dfn[u] == low[u]) {
		++cnt;
		int sz = 0;
		f[cnt] = 0;
		while(!stk.empty()) {
			int v = stk.top();
			stk.pop();
			ins[v] = false;
			bel[v] = cnt;
			sz += (v <= n);
			for(const auto& w: G[v])
				if(bel[w] && bel[w] != cnt)
					f[cnt] = max(f[cnt], f[bel[w]]);
			if(v == u)
				break;
		}
		f[cnt] += sz;
		ans = max(ans, f[cnt]);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int R, C;
	cin >> n >> R >> C;
	for(int k = 1; k <= n; ++k) {
		cin >> x[k] >> y[k] >> ty[k];
		id[{x[k], y[k]}] = k;
		r[x[k]].push_back(k);
		c[y[k]].push_back(k);
	}
	int tot = n;
	for(int k = 1; k <= n; ++k)
		if(ty[k] == 1) {
			if(!rid.count(x[k])) {
				rid[x[k]] = ++tot;
				for(const auto& j: r[x[k]])
					G[tot].push_back(j);
			}
			G[k].push_back(rid[x[k]]);
		} else if(ty[k] == 2) {
			if(!cid.count(y[k])) {
				cid[y[k]] = ++tot;
				for(const auto& i: c[y[k]])
					G[tot].push_back(i);
			}
			G[k].push_back(cid[y[k]]);
		} else if(ty[k] == 3)
			for(int dx = -1; dx <= 1; ++dx)
				for(int dy = -1; dy <= 1; ++dy)
					if(dx || dy) {
						if(!id.count({x[k] + dx, y[k] + dy}))
							continue;
						G[k].push_back(id[{x[k] + dx, y[k] + dy}]);
					}
	for(int u = 1; u <= tot; ++u)
		if(!dfn[u])
			dfs(u);
	cout << ans;
	cout.flush();
	return 0;
}