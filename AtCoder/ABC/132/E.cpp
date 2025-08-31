#include <bits/stdc++.h>
using namespace std;

constexpr const int N = 1e5 + 3;
vector<int> G[N], G2[N];
int n, T, ans = 0x3f3f3f3f;

void dfs1(int u, int gfu, int dep) {
	if(dep == 3) {
		G2[gfu].push_back(u);
		return;
	}
	for(const auto& v: G[u])
		dfs1(v, gfu, dep + 1);
}

void dfs2(int u, int dis) {
	if(u == T) {
		ans = min(ans, dis);
		return;
	} else if(dis > n / 3 || dis > ans)
		return;
	for(const auto& v: G2[u])
		dfs2(v, dis + 1);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int m, S;
	cin >> n >> m;
	for(int u, v; m--; ) {
		cin >> u >> v;
		G[u].push_back(v);
	}
	cin >> S >> T;
	for(int i = 1; i <= n; ++i)
		dfs1(i, i, 0);
	/*for(int i = 1; i <= n; ++i) {
		auto& a = G2[i];
		sort(begin(a), end(a));
		a.erase(unique(begin(a), end(a)), cend(a));
		auto it = lower_bound(cbegin(a), cend(a), i);
		if(it != cend(a) && *it == i)
			a.erase(it);
	}*/
	dfs2(S, 0);
	if(ans == 0x3f3f3f3f)
		cout << "-1";
	else
		cout << ans;
	cout << endl;
	return 0;
}
