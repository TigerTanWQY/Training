#include <iostream>
#include <vector>
#include <algorithm>
#include <atcoder/dsu>
using namespace std;

struct TreeEdgeNode {
	int u, v, w;
	bool operator<(const TreeEdgeNode& x) const
	{ return w < x.w; }
};
vector<TreeEdgeNode> E;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	for(int _ = 1, u, v, w; _ < n; ++_) {
		cin >> u >> v >> w;
		E.push_back({u, v, w});
	}
	sort(E.begin(), E.end());
	atcoder::dsu dsu(n + 1);
	long long ans = 0;
	for(const auto& p: E) {
		ans += 1LL * p.w * dsu.size(p.u) * dsu.size(p.v);
		dsu.merge(p.u, p.v);
	}
	cout << ans;
	return 0;
}