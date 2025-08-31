#include <bits/stdc++.h>
using namespace std;

vector<tuple<int, bool, int, int>> e;
int fa[50003], n;

int fnd(const int x) {
	if(fa[x] != x)
		fa[x] = fnd(fa[x]);
	return fa[x];
}

pair<int, int> Kruskal() {
	sort(e.begin(), e.end());
	for(int i = 0; i <= n; ++i)
		fa[i] = i;
	int res = 0, tmp = 0;
	for(auto [w, c, u, v]: e) {
		u = fnd(u); v = fnd(v);
		if(u == v)
			continue;
		fa[v] = u;
		if(!c)
			++tmp;
		res += w;
	}
	return {res, tmp};
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int m, k;
	cin >> n >> m >> k;
	for(int u, v, w, c; m--; ) {
		cin >> u >> v >> w >> c;
		++u; ++v;
		e.push_back({w, c, u, v});
	}
	int ans = 0;
	for(int L = -101, R = 101; L <= R; ) {
		int M = (L + R) >> 1;
		for(auto& [w, c, u, v]: e)
			if(!c)
				w += M;
		auto [res, tmp] = Kruskal();
		if(tmp >= k) {
			L = M + 1;
			ans = res - k * M;
		} else
			R = M - 1;
		for(auto& [w, c, u, v]: e)
			if(!c)
				w -= M;
	}
	cout << ans << endl;
	return 0;
}
