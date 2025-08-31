#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int N = 103;
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
			ans += w;
			++cnt;
		}
	}
	return cnt == n - 1;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	for(int i = 1, x; i <= n; ++i)
		for(int j = 1; j <= n; ++j) {
			cin >> x;
			e.push_back({i, j, x});
		}
	Kruskal();
	cout << ans;
	return 0;
}