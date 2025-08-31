#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
using namespace std;

constexpr const int N = 2e3 + 3;
vector<tuple<int, int, int>> e;
int fa[N], n;
long long ans = 0;

int fnd(const int x) {
	if(fa[x] != x)
		fa[x] = fnd(fa[x]);
	return fa[x];
}

void Kruskal() {
	sort(e.begin(), e.end());
	for(int i = 0; i <= n; ++i)
		fa[i] = i;
	for(auto [w, u, v]: e) {
		u = fnd(u); v = fnd(v);
		if(u == v)
			continue;
		fa[v] = u;
		ans += w;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n;
	for(int i = 1; i <= n; ++i)
		for(int j = i, w; j <= n; ++j) {
			cin >> w;
			e.push_back({w, i - 1, j});
			e.push_back({w, j, i - 1});
		}
	Kruskal();
	cout << ans << endl;
	return 0;
}