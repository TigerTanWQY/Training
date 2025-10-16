#include <bits/stdc++.h>
using namespace std;

constexpr const int N = 2e4 + 3;
vector<int> G[N], GC[N];
pair<int, int> E[500003];
stack<int> stk;
bool vis[N];
int fa[N], col[N], dfn[N], low[N], sz[N],
	in[N], out[N], cnt, idx;

int fnd(int x)
{ return fa[x] == x? x: fa[x] = fnd(fa[x]); }

void tarjan(int u) {
	low[u] = dfn[u] = ++idx;
	vis[u] = true;
	stk.push(u);
	for(const auto& v: G[u])
		if(!dfn[v]) {
			tarjan(v);
			low[u] = min(low[u], low[v]);
		} else if(vis[v])
			low[u] = min(low[u], dfn[v]);
	if(dfn[u] == low[u]) {
		col[u] = ++cnt;
		vis[u] = false;
		for(; stk.top() != u; stk.pop()) {
			col[stk.top()] = cnt;
			vis[stk.top()] = false;
		}
		stk.pop();
	}
}

void dfs(int u, int fu) {
	if(u != fu)
		fa[fnd(u)] = fnd(fu);
	if(GC[u].empty() && u != fu && !vis[u])
		vis[u] = true;
	for(const auto& v: GC[u])
		dfs(v, fu);
}

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	for(int n, m; cin >> n >> m; cout.put('\n')) {
		idx = cnt = 0;
		for(; !stk.empty(); stk.pop());
		for(int i = 1; i <= n; ++i) {
			fa[i] = i;
			col[i] = low[i] = dfn[i] = sz[i]
				= in[i] = out[i] = 0;
			vis[i] = false;
			G[i].clear(); GC[i].clear();
		}
		for(int i = 1, u, v; i <= m; ++i) {
			cin >> u >> v;
			E[i] = {u, v};
			G[u].push_back(v);
		}
		for(int i = 1; i <= n; ++i)
			if(!dfn[i])
				tarjan(i);
		for(int i = 1; i <= n; ++i)
			vis[i] = false;
		for(int i = 1; i <= m; ++i) {
			int u = col[E[i].first], v = col[E[i].second];
			if(u != v) {
				GC[u].push_back(v);
				++in[v]; ++out[u];
			}
		}
		int cnti = 0, cnto = 0;
		for(int i = 1; i <= cnt; ++i) {
			if(!in[i])
				++cnti;
			if(!out[i])
				++cnto;
		}
		int res = max(cnti, cnto);
		cout << (res == 1? 0: res);
	}
	cout.flush(); return 0;
}
