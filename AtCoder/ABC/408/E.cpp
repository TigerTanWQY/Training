#include <bits/stdc++.h>
#include <atcoder/dsu>
using namespace std;

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	vector<tuple<int, int, unsigned>> E;
	for(int u, v; m--; ) {
		unsigned w;
		cin >> u >> v >> w;
		E.push_back({u, v, w});
	}
	unsigned ans = (1 << 30) - 1;
	for(int b = 29; b >= 0; --b) {
		auto res = ans & ~(1LL << b);
		atcoder::dsu DSU(n + 1);
		for(const auto& [u, v, w]: E) {
			if(w & ~res)
				continue;
			DSU.merge(u, v);
		}
		if(DSU.leader(1) == DSU.leader(n))
			ans = res;
	}
	cout << ans << endl;
	return 0;
}
