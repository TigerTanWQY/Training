#include <bits/stdc++.h>
using namespace std;

constexpr const int N = 1e5 + 3;
vector<int> G[N], ans1, ans2;
int a[N], b[N], dfn[N], low[N], idx = 0, k, l;

void tarjan(int u, int fa) {
	dfn[u] = low[u] = ++idx;
	for(const auto& v: G[u])
		if(!dfn[v]) {
			tarjan(v, u);
			low[u] = min(low[u], low[v]);
			if(low[v] > dfn[u])
				if(!a[v] || !b[v] || a[v] == k || b[v] == l)
				{ ans1.push_back(v); ans2.push_back(u); }
			a[u] += a[v]; b[u] += b[v];
		} else if(v != fa)
			low[u] = min(low[u], dfn[v]);
}

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int m;
	cin >> m >> m >> k >> l;
	for(int i = 1, x; i <= k; ++i) {
		cin >> x;
		a[x] = 1;
	}
	for(int i = 1, x; i <= l; ++i) {
		cin >> x;
		b[x] = 1;
	}
	for(int u, v; m--; ) {
		cin >> u >> v;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	tarjan(1, 0);
	cout << ans1.size() << '\n';
	for(int i = 0; i < ans1.size(); ++i)
		cout << ans1[i] << ' ' << ans2[i] << '\n';
	cout.flush(); return 0;
}
