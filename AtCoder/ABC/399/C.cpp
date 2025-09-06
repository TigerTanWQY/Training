#include <bits/stdc++.h>
#include <atcoder/dsu>
using namespace std;

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	atcoder::dsu DSU(n + 1);
	int cnt = n;
	for(int _ = m, u, v; _--; ) {
		cin >> u >> v;
		if(!DSU.same(u, v))
			--cnt;
		DSU.merge(u, v);
	}
	cout << m - (n - cnt) << '\n';
	return 0;
}
