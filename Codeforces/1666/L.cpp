#include <bits/stdc++.h>
using namespace std;

constexpr const int N = 2e5 + 3;
vector<int> G[N], ans1, ans2;
int fa[N], vis[N], s, rt;

void dfs(int u, int fu) {
	if(u == s)
		return;
	if(vis[u]) {
		if(vis[u] == rt)
			return;
		ans2.push_back(u);
		for(int i = u; i != s && fa[i] != i; i = fa[i])
			ans1.push_back(i);
		for(int i = fu; i != s && fa[i] != i; i = fa[i])
			ans2.push_back(i);
		ans1.push_back(s); ans2.push_back(s);
		cout << "Possible\n" << ans1.size() << '\n';
		for(auto it = ans1.crbegin(); it != ans1.crend(); ++it)
			cout << *it << ' ';
		cout << '\n' << ans2.size() << '\n';
		for(auto it = ans2.crbegin(); it != ans2.crend(); ++it)
			cout << *it << ' ';
		cout << endl; exit(0);
		return;
	}
	vis[u] = rt; fa[u] = fu;
	for(const auto& v: G[u])
		dfs(v, u);
}

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int n, m;
	cin >> n >> m >> s;
	for(int u, v; m--; ) {
		cin >> u >> v;
		G[u].push_back(v);
	}
	for(const auto& v: G[s]) {
		rt = v;
		dfs(v, s);
	}
	cout << "Impossible" << endl;
	return 0;
}
