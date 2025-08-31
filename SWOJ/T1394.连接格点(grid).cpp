#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

const int d[2][2]{{1, 0}, {0, 1}};
const int N = 1003;
struct Edge {
	int u, v, w;
	bool operator<(const Edge& x) const
	{ return w < x.w; }
	bool operator==(const Edge& x) const
	{ return u == x.u && v == x.v && w == x.w; }
};
vector<Edge> e;
int fa[N * N], ans = 0;

int fnd(const int& x) {
	if(fa[x] != x)
		fa[x] = fnd(fa[x]);
	return fa[x];
}

void Kruskal() {
	sort(e.begin(), e.end());
	e.erase(unique(e.begin(), e.end()), e.cend());
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
	int m, n;
	cin >> m >> n;
	for(int i = 1; i <= m * n; ++i)
		fa[i] = i;
	vector<pair<int, int>> vis;
	for(int x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2; ) {
		fa[fnd(m * (x1 - 1) + y1)] = fnd(m * (x2 - 1) + y2);
		vis.push_back({m * (x1 - 1) + y1, m * (x2 - 1) + y2});
		vis.push_back({m * (x2 - 1) + y2, m * (x1 - 1) + y1});
	}
	if(!vis.empty()) {
		sort(vis.begin(), vis.end());
		vis.erase(unique(vis.begin(), vis.end()), vis.cend());
	}
	for(int x1 = 1; x1 <= m; ++x1)
		for(int y1 = 1; y1 <= n; ++y1)
			for(int k = 0; k < 2; ++k) {
				int x2 = x1 + d[0][k], y2 = y1 + d[1][k];
				if(x2 <= m && y2 <= n && (vis.empty() || *lower_bound(vis.cbegin(), vis.cend(), make_pair(x1, y1)) != make_pair(x1, y1) || *lower_bound(vis.cbegin(), vis.cend(), make_pair(x2, y2)) != make_pair(x2, y2))) {
					e.push_back({m * (x1 - 1) + y1, m * (x2 - 1) + y2, k + 1});
					e.push_back({m * (x2 - 1) + y2, m * (x1 - 1) + y1, k + 1});
				}
			}
	Kruskal();
	if(ans == 1)
		ans = 2;
	cout << ans;
	return 0;
}