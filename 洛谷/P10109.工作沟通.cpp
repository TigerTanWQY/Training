#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

constexpr const int N = 303;
vector<int> G[N];
int fa[9 + 3][N], dep[N];

void get_depth(const int u) {
	dep[u] = dep[fa[0][u]] + 1;
	for(const auto& v: G[u])
		get_depth(v);
}

int lca(int u, int v) {
	if(dep[u] < dep[v])
		swap(u, v);
	for(int j = 9; j >= 0; --j)
		if(dep[fa[j][u]] >= dep[v])
			u = fa[j][u];
	if(u == v)
		return u;
	for(int j = 9; j >= 0; --j)
		if(fa[j][u] != fa[j][v]) {
			u = fa[j][u];
			v = fa[j][v];
		}
	return fa[0][u];
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, q;
	cin >> n;
	for(int i = 1; i < n; ++i) {
		cin >> fa[0][i];
		G[fa[0][i]].push_back(i);
	}
	get_depth(0);
	for(int j = 1; j <= 9; ++j)
		for(int i = 0; i < n; ++i)
			fa[j][i] = fa[j - 1][fa[j - 1][i]];
	cin >> q;
	for(int m, x; q--; cout.put('\n')) {
		cin >> m >> x;
		for(int y; --m; ) {
			cin >> y;
			x = lca(x, y);
		}
		int ans = x;
		for(x = fa[0][x]; x; x = fa[0][x])
			ans = max(ans, x);
		cout << ans;
	}
	cout.flush();
	return 0;
}