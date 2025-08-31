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
	for(int i = 1; i <= n; ++i)
		fa[i] = i;
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
	for(int x, y; m--; ) {
		cin >> x >> y;
	}
	Kruskal();
	cout << ans;
	return 0;
}