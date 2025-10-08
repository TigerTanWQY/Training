#include <bits/stdc++.h>
using namespace std;

constexpr const int N = 1e4 + 3;
vector<int> G[N], Ge[N], ans;
bool col[N], vis[N], ins[N];
int c[N], cnt = 0, rt;

void dfs1(int u) {
	vis[u] = true;
	for(int i = 0; i < G[u].size(); ++i) {
		int v = G[u][i], x = Ge[u][i];
		if(!vis[v]) {
			col[v] = col[u] ^ 1;
			ins[x] = true;
			dfs1(v);
		} else if(!ins[x]) {
			ins[x] = true;
			if(col[u] == col[v]) {
				++cnt;
				++c[u];
				--c[v];
				rt = x;
			} else {
				--c[u];
				++c[v];
			}
		}
	}
}

void dfs2(int u) {
	vis[u] = true;
	for(int i = 0; i < G[u].size(); ++i) {
		int v = G[u][i];
		if(!vis[v]) {
			dfs2(v);
			if(c[v] == cnt)
				ans.push_back(Ge[u][i]);
			c[u] += c[v];
		}
	}
}

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	for(int i = 1, u, v; i <= m; ++i) {
		cin >> u >> v;
		G[u].push_back(v);
		Ge[u].push_back(i);
		G[v].push_back(u);
		Ge[v].push_back(i);
	}
	for(int u = 1; u <= n; ++u)
		if(!vis[u])
			dfs1(u);
	if(!cnt) {
		cout << m << '\n';
		for(int i = 1; i <= m; ++i)
			cout << i << ' ';
		cout << endl; return 0;
	}
	memset(vis, 0, sizeof vis);
	for(int u = 1; u <= n; ++u)
		if(!vis[u])
			dfs2(u);
	if(cnt == 1)
		ans.push_back(rt);
	cout << ans.size() << '\n';
	sort(begin(ans), end(ans));
	for(const auto& i: ans)
		cout << i << ' ';
	cout << endl; return 0;
}
