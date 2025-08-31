#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
using namespace std;

constexpr const int N = 1e5 + 3;
tuple<int, int, int> e[N];
int fa[N], sz[N], n;
long long ans = 0;

int fnd(const int x) {
	if(fa[x] != x)
		fa[x] = fnd(fa[x]);
	return fa[x];
}

void Kruskal() {
	sort(e + 1, e + n);
	for(int i = 0; i <= n; ++i) {
		fa[i] = i;
		sz[i] = 1;
	}
	for(int i = 1; i < n; ++i) {
		auto [w, u, v] = e[i];
		u = fnd(u); v = fnd(v);
		if(u == v)
			continue;
		ans += (w + 1LL) * sz[u] * sz[v] - 1;
		sz[u] += sz[v];
		fa[v] = u;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n;
	for(int i = 1, u, v, w; i < n; ++i) {
		cin >> u >> v >> w;
		e[i] = {w, u, v};
	}
	Kruskal();
	cout << ans << endl;
	return 0;
}