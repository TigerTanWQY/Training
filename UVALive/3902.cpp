#include <iostream>
#include <vector>
#include <bitset>
using namespace std;

constexpr const int N = 1'003;
vector<int> G[N], subG[N];
bitset<N> vis;
int fa[N], k;

void dfs1(const int u, const int fau, const int dep) {
	fa[u] = fau;
	if(G[u].size() == 1 && dep > k)
		subG[dep].push_back(u);
	for(const auto& v: G[u])
		if(v != fau)
			dfs1(v, u, dep + 1);
}

void dfs2(const int u, const int fau, const int dep) {
	vis[u] = true;
	for(const auto& v: G[u])
		if(v != fau && dep < k)
			dfs2(v, u, dep + 1);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int _T;
	cin >> _T;
	for(int n, rt; _T--; ) {
		cin >> n >> rt >> k;
		for(int _ = 1, u, v; _ < n; ++_) {
			cin >> u >> v;
			G[u].push_back(v);
			G[v].push_back(u);
		}
		dfs1(rt, 0, 0);
		int ans = 0;
		for(int dep = n - 1; dep > k; --dep)
			for(const auto& u: subG[dep]) {
				if(vis[u])
					continue;
				int v = u;
				for(int _ = 0; _ < k; ++_)
					v = fa[v];
				dfs2(v, 0, 0);
				++ans;
			}
		cout << ans << '\n';
		for(int i = 1; i <= n; ++i) {
			G[i].clear();
			subG[i].clear();
		}
		vis.reset();
	}
	cout.flush();
	return 0;
}