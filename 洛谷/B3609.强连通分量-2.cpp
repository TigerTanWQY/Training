#include <iostream>
#include <vector>
#include <bitset>
#include <algorithm>
using namespace std;

const int N = 10003;
vector<int> G[N], GR[N], out, c;
bitset<N> vis;

void dfs1(const int& u) {
	vis[u] = true;
	for(const auto& v: G[u])
		if(!vis[v])
			dfs1(v);
	out.push_back(u);
}

void dfs2(const int& u) {
	vis[u] = true;
	for(const auto& v: GR[u])
		if(!vis[v])
			dfs2(v);
	c.push_back(u);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, m;
	cin >> n >> m;
	for(int u, v; m--; ) {
		cin >> u >> v;
		G[u].push_back(v);
		GR[v].push_back(u);
	}
	for(int u = 1; u <= n; ++u)
		if(!vis[u])
			dfs1(u);
	reverse(out.begin(), out.end());
	vis = 0;
	vector<vector<int>> scc;
	for(const auto& u: out)
		if(!vis[u]) {
			dfs2(u);
			sort(c.begin(), c.end());
			scc.push_back(c);
			c.clear();
		}
	sort(scc.begin(), scc.end());
	cout << scc.size() << '\n';
	for(const auto& d: scc) {
		for(const auto& u: d)
			cout << u << ' ';
		cout << '\n';
	}
	cout.flush();
	return 0;
}