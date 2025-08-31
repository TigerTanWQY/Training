#include <iostream>
#include <vector>
#include <bitset>
#include <queue>
#include <algorithm>
using namespace std;

constexpr const int N = 50'003, INF = 0x3f3f3f3f;
vector<int> G[N], dfn;
queue<int> tag;
bitset<N> vis;
int q[N], sz[N], maxn[N], dis[N], mp[1003], res[N], n, m, rt, tot;

int read() {
	int ret = 0;
	char ch = cin.get();
	for(; '0' > ch || ch > '9'; ch = cin.get());
	for(; '0' <= ch && ch <= '9'; ch = cin.get())
		ret = ret * 10 + ch - '0';
	return ret;
}

void get_sz(const int u, const int fa) {
	sz[u] = 1;
	maxn[u] = 0;
	for(const auto& v: G[u])
		if(v != fa && !vis[v]) {
			get_sz(v, u);
			maxn[u] = max(maxn[u], sz[v]);
			sz[u] += sz[v];
		}
	maxn[u] = max(maxn[u], tot - sz[u]);
	if(maxn[u] < maxn[rt])
		rt = u;
}

void get_dis(int u, int fa) {
	dfn.push_back(dis[u]);
	for(const auto& v: G[u])
		if(v != fa && !vis[v]) {
			dis[v] = dis[u] + 1;
			get_dis(v, u);
		}
}

void dfs(const int u, const int fa) {
	mp[0] = vis[u] = true;
	tag.push(0);
	for(const auto& v: G[u])
		if(v != fa && !vis[v]) {
			dis[v] = 1;
			get_dis(v, u);
			for(const auto& k: dfn)
				for(int i = 1; i <= m; ++i)
					if(q[i] >= k)
						res[i] += mp[q[i] - k];
			for(int k = 0; k < dfn.size(); ++k)
				if(k < 503) {
					++mp[dfn[k]];
					tag.push(dfn[k]);
				}
			dfn.clear();
		}
	while(!tag.empty()) {
		mp[tag.front()] = 0;
		tag.pop();
	}
	for(const auto& v: G[u])
		if(v != fa && !vis[v]) {
			tot = sz[v];
			rt = 0;
			maxn[rt] = INF;
			get_sz(v, u);
			get_sz(rt, -1);
			dfs(rt, u);
		}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	n = read(); m = 1; q[1] = read();
	for(int _ = 1; _ < n; ++_) {
		int u = read(), v = read();
		G[u].push_back(v);
		G[v].push_back(u);
	}
	rt = 0;
	maxn[rt] = INF;
	tot = n;
	get_sz(1, -1);
	get_sz(rt, -1);
	dfs(rt, -1);
	for(int i = 1; i <= m; ++i)
		cout << res[i] << '\n';
	cout.flush();
	return 0;
}