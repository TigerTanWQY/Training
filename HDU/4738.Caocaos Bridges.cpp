#include <bits/stdc++.h>
using namespace std;

constexpr const int N = 1003, M = 2e6 + 3;
struct Edge
{ int u, v, w; }
E[M];
vector<Edge> G[N];
vector<int> eid;
stack<int> stk;
bool vis[N], ins[M];
int dfn[N], low[N], bel[N], sz[N], idx = 0, cnt = 0;

void dfs(int u, int fid) {
	dfn[u] = low[u] = ++idx;
	stk.push(u);
	vis[u] = true;
	for(const auto& [v, w, id]: G[u]) {
		if(ins[id])
			continue;
		else
			ins[id] = true;
		if(!dfn[v]) {
			dfs(v, id);
			low[u] = min(low[u], low[v]);
		} else if(vis[v])
			low[u] = min(low[u], dfn[v]);
	}
	if(dfn[u] == low[u]) {
		if(~fid)
			eid.push_back(fid);
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
	cin.tie(nullptr)->sync_with_stdio(false);
	for(int n, m; cin >> n >> m && (n || m); cout.put('\n')) {
		for(int i = 1; i <= m; ++i) {
			cin >> E[i].u >> E[i].v >> E[i].w;
			G[E[i].u].push_back({E[i].v, E[i].w, i});
			G[E[i].v].push_back({E[i].u, E[i].w, i});
		}
		dfs(1, -1);
		bool flg = true;
		for(int u = 1; flg && u <= n; ++u)
			if(!vis[u])
				flg = false;
		if(!flg)
			cout << "0";
		else if(cnt == 1)
			cout << "-1";
		else {
			int ans = 0x3f3f3f3f;
			for(const auto& u: eid)
				ans = min(ans, E[u].w);
			if(ans == 0)
				ans = 1;
			cout << ans;
		}
		for(int i = 0; i < N; ++i) {
			G[i].clear();
			dfn[i] = low[i] = bel[i] = sz[i] = 0;
		}
		eid.clear();
		for(; !stk.empty(); stk.pop());
		memset(vis, 0, sizeof vis);
		memset(ins, 0, sizeof ins);
		idx = cnt = 0;
	}
	cout.flush(); return 0;
}
