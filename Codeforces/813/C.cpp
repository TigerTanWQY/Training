#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

constexpr const int N = 200'003;
vector<int> G[N];
int fa[N], to[N], dep[N], beg, ans = 0;

void down(const int u) {
	for(const auto& v: G[u])
		if(v != fa[u]) {
			fa[v] = u;
			dep[v] = dep[u] + 1;
			down(v);
			to[u] = max(to[u], to[v] + 1);
		}
}

void up(const int u) {
	if(u == 0 || dep[beg] - dep[u] >= dep[u] - dep[1])
		return;
	ans = max(ans, (dep[u] - dep[1] + to[u]) * 2);
	up(fa[u]);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	cin >> n >> beg;
	for(int _ = 1, u, v; _ < n; ++_) {
		cin >> u >> v;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	down(1);
	ans = dep[beg] - dep[1];
	up(beg);
	cout << ans;
	cout.flush();
	return 0;
}