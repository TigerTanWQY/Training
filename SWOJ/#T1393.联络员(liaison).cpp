#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int N = 2003;
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

void Kruskal() {
	sort(e.begin(), e.end());
	for(const auto& p: e) {
		int u = fnd(p.u), v = fnd(p.v);
		if(u != v) {
			fa[u] = v;
			ans += p.w;
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int m;
	cin >> n >> m;
	for(int i = 1; i <= n; ++i)
		fa[i] = i;
	for(int p, u, v, w; m--; ) {
		cin >> p >> u >> v >> w;
		if(p == 1) {
			int fu = fnd(u), fv = fnd(v);
			if(fu != fv)
				fa[fu] = fv;
			ans += w;
		} else {
			e.push_back({u, v, w});
			e.push_back({v, u, w});
		}
	}
	Kruskal();
	cout << ans;
	return 0;
}