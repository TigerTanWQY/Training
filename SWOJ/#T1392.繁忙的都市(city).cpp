#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int N = 303;
struct Edge {
	int u, v, w;
	bool operator<(const Edge& x) const
	{ return w < x.w; }
};
vector<Edge> e;
int fa[N], n, ans = 0;

int fnd(const int& x) {
	if(fa[x] != x)
		fa[x] = fnd(fa[x]);
	return fa[x];
}

bool Kruskal() {
	sort(e.begin(), e.end());
	for(int i = 1; i <= n; ++i)
		fa[i] = i;
	int cnt = 0;
	for(const auto& p: e) {
		int u = fnd(p.u), v = fnd(p.v), w = p.w;
		if(u != v) {
			fa[u] = v;
			ans = max(ans, w);
			++cnt;
		}
	}
	return cnt == n - 1;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int m;
	cin >> n >> m;
	for(int u, v, w; m--; ) {
		cin >> u >> v >> w;
		e.push_back({u, v, w});
		e.push_back({v, u, w});
	}
	Kruskal();
	cout << n - 1 << ' ' << ans;
	return 0;
}