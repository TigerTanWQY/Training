#include <bits/stdc++.h>
using namespace std;

constexpr const int N = 303;
vector<tuple<int, int, int>> e;
int fa[N], n;

int fnd(const int x) {
	if(fa[x] != x)
		fa[x] = fnd(fa[x]);
	return fa[x];
}

int Kruskal() {
	int res = 0;
	sort(e.begin(), e.end());
	for(int i = 0; i <= n; ++i)
		fa[i] = i;
	for(auto [w, u, v]: e) {
		u = fnd(u); v = fnd(v);
		if(u == v)
			continue;
		fa[v] = u;
		res += w;
	}
	return res;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n;
	for(int i = 1, w; i <= n; ++i) {
		cin >> w;
		e.push_back({w, 0, i});
	}
	for(int i = 1, w; i <= n; ++i)
		for(int j = 1; j <= n; ++j) {
			cin >> w;
			e.push_back({w, i, j});
		}
	cout << Kruskal() << endl;
	return 0;
}