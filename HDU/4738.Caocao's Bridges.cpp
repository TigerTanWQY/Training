#include <iostream>
#include <vector>
#include <bitset>
#include <stack>
#include <algorithm>
using namespace std;

constexpr const int N = 1'003;
constexpr const int M = 2'000'003;
struct Edge
{ int u, v, w; };
vector<Edge> G[N];
vector<int> eid;
stack<int> stk;
bitset<N> vis;
bitset<M> ins;
Edge e[M];
int dep[N], low[N], bel[N], sz[N], cnt = 0;

void dfs(const int& u, const int& fa, const int& fid) {
	dep[u] = low[u] = dep[fa] + 1;
	stk.push(u);
	vis[u] = true;
	for(const auto& [v, w, id]: G[u]) {
		if(ins[id])
			continue;
		else
			ins[id] = true;
		if(!dep[v]) {
			dfs(v, u, id);
			low[u] = min(low[u], low[v]);
		} else if(vis[v])
			low[u] = min(low[u], dep[v]);
	}
	if(dep[u] == low[u]) {
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
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	for(int n, m; cin >> n >> m && (n || m); ) {
		for(int i = 1; i <= m; ++i) {
			cin >> e[i].u >> e[i].v >> e[i].w;
			G[e[i].u].push_back({e[i].v, e[i].w, i});
			G[e[i].v].push_back({e[i].u, e[i].w, i});
		}
		dfs(1, 0, -1);
		bool flag = true;
		for(int u = 1; flag && u <= n; ++u)
			if(!vis[u])
				flag = false;
		if(!flag)
			cout << "0\n";
		else if(cnt == 1)
			cout << "-1\n";
		else {
			int ans = 0x3f3f3f3f;
			for(const auto& u: eid)
				ans = min(ans, e[u].w);
			if(ans == 0)
				ans = 1;
			cout << ans << '\n';
		}
		for(int i = 0; i < N; ++i) {
			G[i].clear();
			dep[i] = low[i] = bel[i] = sz[i] = 0;
		}
		eid.clear();
		for(; !stk.empty(); stk.pop());
		vis = 0;
		ins = 0;
		cnt = 0;
	}
	cout.flush();
	return 0;
}