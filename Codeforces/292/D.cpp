#include <bits/stdc++.h>
using namespace std;

struct DSU {
	int fa[503];
	DSU(const int n) {
		for(int i = 0; i <= n; ++i)
			fa[i] = i;
	}
	int fnd(const int x) {
		if(fa[x] != x)
			fa[x] = fnd(fa[x]);
		return fa[x];
	}
	void mrge(int x, int y) {
		x = fnd(x); y = fnd(y);
		if(x > y)
			swap(x, y);
		fa[y] = x;
	}
};
pair<int, int> in[10003];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, m, q;
	cin >> n >> m;
	vector<DSU> La{DSU(n)}, Ra = La;
	for(int i = 1; i <= m; ++i)
		cin >> in[i].first >> in[i].second;
	for(int i = 1, j = m; i <= m && j; ++i, --j) {
		auto nwL = La.back(), mwR = Ra.back();
		nwL.mrge(in[i].first, in[i].second);
		mwR.mrge(in[j].first, in[j].second);
		La.push_back(nwL); Ra.push_back(mwR);
	}
	cin >> q;
	for(int L, R; q--; cout.put('\n')) {
		cin >> L >> R;
		auto Ls = La[L - 1], Rs = Ra[m - R];
		for(int i = 1; i <= n; ++i)
			Ls.mrge(Ls.fa[i], Rs.fa[i]);
		int ans = 0;
		for(int i = 1; i <= n; ++i)
			if(Ls.fa[i] == i)
				++ans;
		cout << ans;
	}
	cout.flush();
	return 0;
}
